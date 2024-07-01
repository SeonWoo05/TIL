import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

# 데이터 불러오기
path = 'df_IQR_done_nonefactor.csv'  # 실제 파일 경로로 변경
df = pd.read_csv(path, encoding="euc-kr")

# 데이터 표준화
scaler = StandardScaler()
df_scaled = scaler.fit_transform(df)

# 주성분 분석(PCA) 수행 (주성분 2개로 설정)
pca = PCA(n_components=2)
principal_components = pca.fit_transform(df_scaled)

# 주성분 데이터프레임 생성
pc_df = pd.DataFrame(data=principal_components, columns=['PC1', 'PC2'])

# 엘보우 방법을 통해 최적의 클러스터 수 결정 (클러스터 수 1~6 범위)
sse = []
for k in range(1, 7):
    kmeans = KMeans(n_clusters=k, random_state=0, max_iter=300, n_init=10)
    kmeans.fit(pc_df)
    sse.append(kmeans.inertia_)

# SSE 그래프 그리기
plt.plot(range(1, 7), sse, marker='o')
plt.xlabel('클러스터 수')
plt.ylabel('SSE')
plt.title('엘보우 방법 - 최적의 클러스터 수')
plt.show()

# K-평균 클러스터링 수행 (엘보우 방법 결과로 3개의 클러스터 설정)
kmeans = KMeans(n_clusters=3, random_state=0, max_iter=300, n_init=10)
kmeans.fit(pc_df)

# 클러스터 레이블
cluster_labels = kmeans.labels_

# 클러스터 레이블을 데이터프레임에 추가
pc_df['Cluster'] = cluster_labels

# 클러스터링 결과 시각화
plt.figure(figsize=(10, 7))
for cluster in range(3):
    cluster_data = pc_df[pc_df['Cluster'] == cluster]
    plt.scatter(cluster_data['PC1'], cluster_data['PC2'], label=f'Cluster {cluster}')

plt.xlabel('주성분 1')
plt.ylabel('주성분 2')
plt.title('PCA 및 K-평균 클러스터링 결과')
plt.legend()
plt.show()

# 주성분과 클러스터 레이블이 포함된 데이터프레임 출력
print(pc_df)