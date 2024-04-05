import pandas as pd
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler

# 데이터 불러오기
pd.set_option('display.max_rows', None)  # 행의 최대 출력 제한 해제
pd.set_option('display.max_columns', None)  # 열의 최대 출력 제한 해제
pd.set_option('display.width', None)
df = pd.read_csv("datafile2.csv",nrows=16, index_col=0, encoding="euc-kr")

# 안심택배함이 존재하지 않아 이용률이 NaN인 행을 이용률의 평균으로 보간
df.iloc[:, 13].fillna(df.iloc[:, 13].mean(), inplace=True)

df1 = df.iloc[:, [0, 1, 2, 9]].copy()
df2 = df.iloc[:, [3, 4, 10, 11]].copy()
df3 = df.iloc[:, [5, 6, 7, 8, 13]].copy()


print(df3)

# # 이용객 수가 0인 곳의 지하철 이용객 수 추정
# non_zero_bus = df[df['버스'] != 0]['버스'].mean()
# non_zero_subway = df[df['지하철'] != 0]['지하철'].mean()
# bus_subway_ratio = non_zero_subway / non_zero_bus

# # 버스 이용객 수를 기반으로 지하철 이용객 수 보간
# df['지하철'] = df.apply(lambda x: x['버스'] * bus_subway_ratio if x['지하철'] == 0 else x['지하철'], axis=1)
# df['지하철'] = df['지하철'].astype(int)

# 독립 변수 선택
features = ['인구수', '1인가구수', '여성인구수', 'cctv 개수', '경찰서', '버스', '지하철', '여성 길단위 상존인구', '여성 건물단위 상존인구',
            '2,30대 1인가구 여성인구', '경찰관서 접근 취약인구수', '치안시설 분포', '안심택배함 이용률']

X = df[features]

# 데이터 표준화
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# 주성분 분석 수행
pca = PCA()
X_pca = pca.fit_transform(X_scaled)

# 주성분 분석 결과 확인
explained_variance_ratio = pca.explained_variance_ratio_
print("주성분 분석 결과:")
for i, ratio in enumerate(explained_variance_ratio):
    print(f"주성분 {i+1} 설명 비율: {ratio:.2f}")

from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

X_cluster = X

# 엘보우 메서드를 사용하여 적절한 클러스터 수 결정
sse = []
for k in range(1, 11):
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(X_cluster)
    sse.append(kmeans.inertia_)

# SSE에 대한 그래프 그리기
plt.plot(range(1, 11), sse, marker='o')
plt.xlabel('Number of Clusters')
plt.ylabel('SSE')
plt.title('Elbow Method')
plt.show()

# -----------------------------------------------------------주성분 분석을 통해서 나온 주성분들이 X_cluster
# KMeans 모델 학습
kmeans = KMeans(n_clusters=3, random_state=42)  # 예시로 3개의 클러스터를 설정 / 일관된 값을 얻기 위해 seed 지정
kmeans.fit(X_cluster)

# 클러스터 할당 결과 확인
cluster_labels = kmeans.labels_

# 클러스터링 결과 시각화를 위해 주성분 1, 2만 사용
# plt.scatter(X_pca[:, 0], X_pca[:, 1], c=cluster_labels, cmap='viridis')
# plt.xlabel('Principal Component 1')
# plt.ylabel('Principal Component 2')
# plt.title('Clustering Result')
# plt.colorbar(label='Cluster')
# plt.show()


import seaborn as sns
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm  # 한글 폰트 설정

# 한글 폰트 설정
plt.rcParams['font.family'] = 'Malgun Gothic'

# features 변수 바로 사용하기 위해 지하철 변수 삭제
#features.remove('지하철')

# 각 클러스터에 속한 데이터를 추출
cluster_0 = X_cluster[cluster_labels == 0]
cluster_1 = X_cluster[cluster_labels == 1]
cluster_2 = X_cluster[cluster_labels == 2]

# 각 변수에 대한 밀도 함수 그리기
fig, axes = plt.subplots(3, 5, figsize=(18, 12))  # 2행 3열의 subplot을 만듦

cluster_names = ['A', 'B', 'C']
cluster_colors = ['red', 'blue', 'green']  # 각 군집에 대한 색깔 지정

for i, feature in enumerate(features):
    row = i // 5  # subplot의 행 인덱스
    col = i % 5   # subplot의 열 인덱스
    ax = axes[row, col]  # 해당 위치의 subplot을 선택
    
    # 각 클러스터의 밀도 함수 그리기
    sns.kdeplot(cluster_0[feature], label='Cluster 0', shade=True, color=cluster_colors[0], ax=ax)
    sns.kdeplot(cluster_1[feature], label='Cluster 1', shade=True, color=cluster_colors[1], ax=ax)
    sns.kdeplot(cluster_2[feature], label='Cluster 2', shade=True, color=cluster_colors[2], ax=ax)
    
    ax.set_title(feature)  # subplot의 제목 설정
    
    # 군집에 대한 설명 추가
    ax.text(0.05, 0.95, cluster_names[0], transform=ax.transAxes, ha='left', va='top', color=cluster_colors[0])
    ax.text(0.05, 0.85, cluster_names[1], transform=ax.transAxes, ha='left', va='top', color=cluster_colors[1])
    ax.text(0.05, 0.75, cluster_names[2], transform=ax.transAxes, ha='left', va='top', color=cluster_colors[2])

# 레이아웃 조정
plt.tight_layout()
plt.show()

# 각 데이터 포인트에 대한 클러스터 할당 결과 확인
df['Cluster'] = cluster_labels

# 각 클러스터에 속하는 동 출력
for cluster_id in range(3):
    cluster_data = df[df['Cluster'] == cluster_id]
    print(f"Cluster {cluster_id}에 속하는 동:")
    print(cluster_data['동'].tolist())