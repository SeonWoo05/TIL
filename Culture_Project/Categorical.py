import pandas as pd
df = pd.read_csv(df_Category_Final.csv, encoding='euc-kr')
df = df.drop(columns=['AGE_FLAG'])

# 1. 등구간 범주화
df.columns
df.describe()

def categorize_age(age):
    if age < 15:
        return 0
    elif age < 20:
        return 1
    elif age < 25:
        return 2
    elif age < 30:
        return 3
    elif age < 35:
        return 4
    else:
        return 5
df['AGE'] = df['AGE'].apply(categorize_age)
df['AGE'].unique()

def categorize_age(Height):
    if Height < 140:
        return 0
    elif Height < 150:
        return 1
    elif Height < 160:
        return 2
    elif Height < 170:
        return 3
    elif Height < 180:
        return 4
    else:
        return 5
df['Height'] = df['Height'].apply(categorize_age)
df['Height'].unique()

def categorize_age(Weight):
    if Weight < 40:
        return 0
    elif Weight < 60:
        return 1
    elif Weight < 80:
        return 2
    else:
        return 3
df['Weight'] = df['Weight'].apply(categorize_age)
df['Weight'].unique()

def categorize_age(BMI):
    if BMI < 18.4:
        return 0
    elif BMI < 22.9:
        return 1
    elif BMI < 24.9:
        return 2
    elif BMI < 29.9:
        return 3
    else:
        return 4
df['BMI'] = df['BMI'].apply(categorize_age)
df['BMI'].unique()

def categorize_age(Waist):
    if Waist < 60:
        return 0
    elif Waist < 70:
        return 1
    elif Waist < 80:
        return 2
    elif Waist < 90:
        return 3
    else:
        return 4
df['Waist'] = df['Waist'].apply(categorize_age)
df['Waist'].unique()

df['Blood_Pressure_Status'] = 'Normal'
df.loc[(df['Low_BP'] < 60) | (df['High_BP'] < 90), 'Blood_Pressure_Status'] = 'Low'
df.loc[(df['Low_BP'] >= 90) | (df['High_BP'] >= 140), 'Blood_Pressure_Status'] = 'High'
from sklearn.preprocessing import LabelEncoder
df['Blood_Pressure_Status'] = df['Blood_Pressure_Status'].astype('category')
label_encoder = LabelEncoder()
df['Blood_Pressure_Status'] = label_encoder.fit_transform(df['Blood_Pressure_Status'])

df['Blood_Pressure_Status'].unique()

def categorize_age(Relative_Grap_strength):
    if Relative_Grap_strength < 30:
        return 0
    elif Relative_Grap_strength < 50:
        return 1
    elif Relative_Grap_strength < 70:
        return 2
    else:
        return 3
df['Relative_Grap_strength'] = df['Relative_Grap_strength'].apply(categorize_age)
df['Relative_Grap_strength'].unique()

def categorize_age(Body_Fat):
    if Body_Fat < 1:
        return 0
    elif Body_Fat < 15:
        return 1
    elif Body_Fat < 30:
        return 2
    else:
        return 3
df['Body_Fat'] = df['Body_Fat'].apply(categorize_age)
df['Body_Fat'].unique()

df = df.drop(columns=['Low_BP'])
df = df.drop(columns=['High_BP'])
df = df.drop(columns=['Left_Grap_Strength'])
df = df.drop(columns=['Right_Grap_Strength'])
df.describe()

df.to_csv('df_범주화최종.csv', index=False, encoding='euc-kr')