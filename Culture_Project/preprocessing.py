import pandas as pd
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler

# CSV 파일 읽어오기
try:
    data = pd.read_csv("df_cleaned_Labeled.csv", encoding="euc-kr")
    print("CSV 파일을 성공적으로 읽어왔습니다.")
except FileNotFoundError:
    print("파일을 찾을 수 없습니다. 파일 경로를 확인하세요.")
    exit()
except Exception as e:
    print(f"파일을 읽는 중 오류가 발생했습니다: {e}")
    exit()

# 데이터 확인
print("데이터 정보:")
print(data.info())
print(data.head())

# 결측치가 있는 행 제거
data_cleaned = data.dropna()

# 마지막 열 제거
data_cleaned = data_cleaned.iloc[:, :-1]

# 데이터 확인 (결측치 제거 후, 마지막 열 제거 후)
print("결측치 제거 및 마지막 열 제거 후 데이터 정보:")
print(data_cleaned.info())

# 데이터 스케일링
scaler = StandardScaler()
try:
    scaled_data = scaler.fit_transform(data_cleaned)
    print("데이터 스케일링 성공.")
except Exception as e:
    print(f"데이터 스케일링 중 오류가 발생했습니다: {e}")
    exit()

# K-Means 군집화
try:
    kmeans = KMeans(n_clusters=5)
    kmeans.fit(scaled_data)
    clusters = kmeans.labels_
    print("K-Means 군집화 성공.")
except Exception as e:
    print(f"K-Means 군집화 중 오류가 발생했습니다: {e}")
    exit()

# 클러스터 결과 추가
data_cleaned['Cluster'] = clusters
print("클러스터링 결과:")
print(data_cleaned.head())