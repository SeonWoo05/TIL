import numpy as np
import pandas as pd
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler
import seaborn as sns

# 데이터 불러오기
pd.set_option('display.max_rows', None)  # 행의 최대 출력 제한 해제
pd.set_option('display.max_columns', None)  # 열의 최대 출력 제한 해제
pd.set_option('display.width', None)
df = pd.read_csv("datafile2.csv",nrows=15, index_col=0, encoding="euc-kr")

# 안심택배함이 존재하지 않아 이용률이 NaN인 행을 이용률의 평균으로 보간
df.iloc[:, 13].fillna(df.iloc[:, 13].mean(), inplace=True)

df1 = df.iloc[:, [0, 1, 2, 9]].copy()
df2 = df.iloc[:, [3, 4, 10, 11]].copy()
df3 = df.iloc[:, [5, 6, 7, 8]].copy()

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
features1 = features[:3] + [features[9]]
features2 = [features[3], features[4], features[10], features[11]]
features3 = features[5:9]

X = df[features1]
Y = df[features2]
Z = df[features3]

# 데이터 표준화
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)
Y_scaled = scaler.fit_transform(Y)
Z_scaled = scaler.fit_transform(Z)

# 주성분 분석 결과 확인 함수 만들기
def pca_result_with_coefficients(pca, features):
    explained_variance_ratio = pca.explained_variance_ratio_
    components = pca.components_
    print("주성분 분석 결과:")
    for i, (ratio, component) in enumerate(zip(explained_variance_ratio, components), 1):
        print(f"주성분 {i} 설명 비율: {ratio:.2f}")
        print("주성분에 기여하는 변수 계수:")
        for j, (feature, coefficient) in enumerate(zip(features, component), 1):
            print(f"  {j}. {feature}: {coefficient:.2f}")
        print()

# 주성분 분석 및 결과 출력
pca = PCA()
X_pca = pca.fit_transform(X_scaled)
pca_result_with_coefficients(pca, features1)

Y_pca = pca.fit_transform(Y_scaled)
pca_result_with_coefficients(pca, features2)

Z_pca = pca.fit_transform(Z_scaled)
pca_result_with_coefficients(pca, features3)

# 주성분 분석 수행 결과 주성분 채택 (각각 주성분 1,2만 채택)
X_pca_selected = X_pca[:,:2]
Y_pca_selected = Y_pca[:,:2]
Z_pca_selected = Z_pca[:,:2]
combined_pca_selected = np.concatenate((X_pca_selected, Y_pca_selected, Z_pca_selected), axis=1)

from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

sse = []
for k in range(1, 11):
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(combined_pca_selected)
    sse.append(kmeans.inertia_)

# # SSE에 대한 그래프 그리기
# plt.plot(range(1, 11), sse, marker='o')
# plt.xlabel('Number of Clusters')
# plt.ylabel('SSE')
# plt.title('Elbow Method - Optiaml number of clusters')
# plt.show()



# KMeans 모델 학습
kmeans = KMeans(n_clusters=6, random_state=42)  # 엘보우 메소드의 결과로 6개의 클러스터를 설정 / 일관된 값을 얻기 위해 seed 지정
kmeans.fit(combined_pca_selected)

# 클러스터 할당 결과 확인
cluster_labels = kmeans.labels_

# 각 군집에 속한 동 출력
for cluster_num in range(6):
    print(f"Cluster {cluster_num}:")
    for idx, label in enumerate(cluster_labels):
        if label == cluster_num:
            print(df.index[idx])

# 각 클러스터에 속한 데이터를 추출
clusters = []
for cluster_num in range(6):
    cluster_data = combined_pca_selected[cluster_labels == cluster_num]
    clusters.append(cluster_data)




import seaborn as sns
import matplotlib.pyplot as plt

# 서브플롯 생성
fig, axes = plt.subplots(2, 3, figsize=(18, 12))

# 각 변수에 대해 밀도 함수 그리기
for i, ax in enumerate(axes.flatten()):
    # 각 클러스터에 대한 밀도 함수 그리기
    for cluster_num in range(6):
        cluster_data = clusters[cluster_num]
        sns.kdeplot(cluster_data[:, i], label=f'Cluster {cluster_num}', fill=True, ax=ax, warn_singular=False)
    
    ax.set_title(f'Variable {i+1}')  # 서브플롯의 제목 설정
    ax.set_xlabel('Value')  # x축 레이블 설정
    ax.set_ylabel('Density')  # y축 레이블 설정
    ax.legend()  # 범례 추가

plt.tight_layout()
plt.show()