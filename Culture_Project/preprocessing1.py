import pandas as pd
import numpy as np

# 데이터 로드
data = pd.read_csv("df_cleaned_Labeled.csv", encoding="euc-kr")

# 연속 변수 목록
continuous_vars = ['Height', 'Weight', 'BMI', 'Body_Fat', 'Waist', 'Low_BP', 'High_BP', 'Left_Grap_Strength', 'Right_Grap_Strength', 'Relative_Grap_strength']

# 연속 변수만 추출
data_continuous = data[continuous_vars]

# Z-점수 계산
z_scores = np.abs((data_continuous - data_continuous.mean()) / data_continuous.std())

# 이상치가 아닌 데이터만 선택 (Z-점수가 3 미만인 데이터 포인트)
data_clean = data[(z_scores < 3).all(axis=1)]

# 정상치 데이터 CSV 파일로 저장
data_clean.to_csv("cleaned_data.csv", index=False, encoding="euc-kr")
print(f"정상치 데이터 포인트 수: {data_clean.shape[0]}")

# 각 변수별 Z-점수 최대값 확인
max_z_scores = z_scores.max()
print("각 변수별 Z-점수 최대값:")
print(max_z_scores)

# 정상치 데이터 포인트 시각화
import matplotlib.pyplot as plt
import seaborn as sns

plt.figure(figsize=(15, 10))
sns.boxplot(data=data_clean[continuous_vars])
plt.xticks(rotation=45)
plt.title('정상치 데이터 포인트의 박스 플롯 (Z-점수)')
plt.show()
