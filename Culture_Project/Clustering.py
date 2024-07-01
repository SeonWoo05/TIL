#!pip install kmodes

import pandas as pd
import numpy as np
from kmodes.kmodes import KModes
import matplotlib.pyplot as plt
df = pd.read_csv("C:/Users/qorud/OneDrive/바탕 화면/문화 공모전/df_범주화최최종.csv",
                 encoding='euc-kr')
Exercise_PRSCRPTN=df["Exercise_PRSCRPTN"]
df = df.drop(columns=['Exercise_PRSCRPTN'])

cost = []
K = range(1, 2)
for num in K:
    kmode = KModes(n_clusters = num, n_init = 3)
    kmode.fit_predict(df)
    cost.append(kmode.cost_)

plt.plot(K, cost, 'bx-')
plt.xlabel('number of clusters')
plt.ylabel('cost')
plt.title('elbow method for finding optimal K')
plt.show()

kmode = KModes(n_clusters = 60, n_init = 2000)
clusters = kmode.fit_predict(df)
df['clusters'] = clusters
df.head()

df[df["clusters"]==0]
df[df["clusters"]==1]
df[df["clusters"]==2]
df[df["clusters"]==3]