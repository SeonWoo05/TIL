import pandas as pd

# 변수의 이름과 주성분에 대한 계수를 리스트로 저장
variables = ['인구수', '1인가구수', '여성인구', '여성 길단위 상존인구', '여성 건물단위 상존인구', 'cctv', '경찰서', '버스', '지하철']
coefficients_pc1 = [-0.5146, -0.0831, -0.5230, -0.4273, -0.4903, -0.0940, -0.1407, -0.0475, 0.0302]
coefficients_pc2 = [-0.0736, 0.5330, 0.0666, 0.1327, -0.1467, -0.2367, -0.0932, 0.5476, 0.5499]

# 주성분 1에 대한 데이터프레임 생성
df_pc1 = pd.DataFrame({'Variable': variables, 'Coefficient_PC1': coefficients_pc1})

# 주성분 2에 대한 데이터프레임 생성
df_pc2 = pd.DataFrame({'Variable': variables, 'Coefficient_PC2': coefficients_pc2})

# 두 데이터프레임을 합쳐서 최종 데이터프레임 생성
df_final = pd.merge(df_pc1, df_pc2, on='Variable')

# 결과 출력
print(df_final)

# DataFrame을 CSV 파일로 저장
df_final.to_csv('coefficients.csv', index=False)