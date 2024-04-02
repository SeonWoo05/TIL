import pandas as pd
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler

# 데이터 불러오기
data = {
    '동': ['광장동', '구의1동', '구의2동', '구의3동', '군자동', '능동', '화양동', '자양1동', '자양2동', '자양3동', '자양4동', '중곡1동', '중곡2동', '중곡3동', '중곡4동'],
    '인구': [34168, 23387, 26043, 28211, 19425, 11180, 23437, 21862, 23946, 27553, 17926, 15299, 20999, 15945, 28035],
    '1인가구수': [3110, 5591, 3049, 3110, 5546, 3251, 12704, 4616, 3098, 2131, 3751, 3282, 3780, 3144, 3747],
    '여성인구': [17694, 12547, 13778, 14842, 11016, 6226, 15286, 11836, 12361, 14424, 11951, 8248, 11105, 8171, 14415],
    'cctv': [44, 0, 43, 17, 5, 11, 14, 11, 6, 24, 2, 2, 10, 75, 14],
    '경찰서': [1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1],
    '버스': [5060, 6172, 7439, 5918, 8221, 6309, 11939, 5648, 6052, 5982, 5695, 4315, 5106, 4648, 3279],
    '지하철': [13014, 20833, 15944, 31738, 0, 36999, 56089, 0, 0, 0, 13864, 0, 0, 8383, 0],
    '여성 길단위 상존인구': [3714735, 4071839, 3740631, 4214050, 2790074, 1338092, 4932788, 5033056, 2904492, 3789449, 4064223, 2163859, 2780134, 3070740, 4600885],
    '여성 건물단위 상존인구': [18238, 11771, 13103, 15516, 10045, 6163, 11111, 11616, 13735, 15973, 9325, 8062, 11540, 8832, 15703],
    '2,30대 1인가구 여성인구': [208, 2122, 649, 978, 1987, 1297, 5996, 1461, 726, 441, 1015, 1178, 1237, 670, 695],
    '치안시설 분포': [1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 2, 1, 1, 1, 2],
    '면적(k㎡)': [2.39, 0.56, 1.39, 1.02, 0.74, 1.1, 1.16, 0.57, 1.68, 1.2, 1.16, 0.62, 0.55, 0.6, 2.32],
    '안심택배함 이용률': [0, 27.09091, 35.18182, 0, 3.75, 0, 36.54545, 0, 10.4545445, 49.09091, 40.727275, 33.27273, 32, 39.81818, 0],
    '안심택배함 개수': [0, 2, 1, 0, 1, 0, 1, 0, 2, 1, 2, 1, 1, 1, 0]
}

df = pd.DataFrame(data)

df = pd.DataFrame(data)

# 이용객 수가 0인 곳의 지하철 이용객 수 추정
non_zero_bus = df[df['버스'] != 0]['버스'].mean()
non_zero_subway = df[df['지하철'] != 0]['지하철'].mean()
bus_subway_ratio = non_zero_subway / non_zero_bus

# 버스 이용객 수를 기반으로 지하철 이용객 수 보간
df['지하철'] = df.apply(lambda x: x['버스'] * bus_subway_ratio if x['지하철'] == 0 else x['지하철'], axis=1)
df['지하철'] = df['지하철'].astype(int)

# 독립 변수 선택
features = ['인구', '1인가구수', '여성인구', 'cctv', '경찰서', '버스', '지하철', '여성 길단위 상존인구', '여성 건물단위 상존인구',
            '2,30대 1인가구 여성인구', '치안시설 분포', '면적(k㎡)', '안심택배함 이용률', '안심택배함 개수']

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

# 주성분 분석 결과에서 설명 비율이 0인 지하철 변수를 제외한 데이터
# X_cluster = X.iloc[:, :-1]  # 마지막 열인 '지하철' 변수 제외
X_cluster = X


# KMeans 모델 학습
kmeans = KMeans(n_clusters=3, random_state=42)  # 예시로 3개의 클러스터를 설정
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
plt.rcParams['font.family'] = 'NanumGothic'

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