import pandas as pd
import numpy as np
from sklearn.cluster import DBSCAN
from sklearn.metrics import pairwise_distances_argmin_min
import matplotlib.pyplot as plt
import gower

# 데이터 불러오기
df = pd.read_csv('PCA_scores.csv', encoding='ISO-8859-1')

# 데이터 확인
print(df.head())

# 샘플링 (데이터셋 크기에 따라 적절히 조정)
sample_size = 24000  # 샘플 크기 설정
if len(df) > sample_size:
    df_sample = df.sample(n=sample_size, random_state=42)
else:
    df_sample = df

# Gower 거리 계산
gower_distances = gower.gower_matrix(df_sample)

# k-distance 그래프 그리기 함수
def plot_k_distance(gower_distances, k):
    from sklearn.neighbors import NearestNeighbors
    nbrs = NearestNeighbors(n_neighbors=k, metric='precomputed').fit(gower_distances)
    distances, indices = nbrs.kneighbors(gower_distances)
    distances = np.sort(distances[:, k-1], axis=0)
    plt.figure(figsize=(10, 6))
    plt.plot(distances)
    plt.xlabel('Data Points sorted by distance')
    plt.ylabel(f'{k}-th Nearest Neighbor Distance')
    plt.title(f'K-distance Graph for k={k}')
    plt.show()

# k-distance 그래프 그리기 (1%가 240)
k = 480
plot_k_distance(gower_distances, k)

# k-distance 그래프에서 적절한 eps 값 선택
eps = 0.15

# DBSCAN 알고리즘 적용 (Gower 거리 행렬을 사용)
dbscan = DBSCAN(eps=eps, min_samples=k, metric='precomputed')
df_sample['cluster'] = dbscan.fit_predict(gower_distances)

# 클러스터 중심 계산을 위해 모든 특성을 고려한 데이터프레임 생성
cluster_centers = df_sample.groupby('cluster').mean()

# 'cluster' 열을 제외한 나머지 열들만 선택
cluster_columns = [col for col in df_sample.columns if col != 'cluster']

# 원본 데이터의 각 포인트를 가장 가까운 클러스터 중심에 할당
df['cluster'] = -1  # 초기화

# 원본 데이터와 샘플 데이터에서 동일한 열 선택
common_columns = df.columns.intersection(cluster_columns)

# pairwise_distances_argmin_min 함수를 사용하여 클러스터 할당
for idx, row in df[common_columns].iterrows():
    point = row.values.reshape(1, -1)
    closest_center, _ = pairwise_distances_argmin_min(point, cluster_centers[common_columns].values)
    df.at[idx, 'cluster'] = df_sample['cluster'].iloc[closest_center[0]]

# 각 설정에 대한 군집 라벨 분포 확인
print(df['cluster'].value_counts())

# 결과 저장
df.to_csv('dbscan_gower_result.csv', index=False)

# 군집 결과 시각화 (예: 2차원 공간에 'P1'와 'P2'를 플로팅)
plt.figure(figsize=(10, 6))
plt.scatter(df['P1'], df['P2'], c=df['cluster'], cmap='viridis', marker='o')
plt.xlabel('Principal Component 1 (P1)')
plt.ylabel('Principal Component 2 (P2)')
plt.title(f'DBSCAN Clustering with eps={eps}')
plt.colorbar(label='Cluster')
plt.show()
