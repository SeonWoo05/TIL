import pandas as pd
from collections import Counter

# Load the CSV file with euc-kr encoding
file_path = 'df_clustered_kmode.csv'
df = pd.read_csv(file_path, encoding='euc-kr')

# Function to process the Exercise_PRSCRPTN column
def process_exercises(exercise_str):
    # Remove the specific substrings
    exercise_str = exercise_str.replace('준비운동:', '준비운동').replace('본운동:', '본운동').replace('마무리운동:', '마무리운동')
    # Split into parts
    parts = exercise_str.split(' / ')
    exercise_dict = {'준비운동': [], '본운동': [], '마무리운동': []}
    for part in parts:
        if '준비운동' in part:
            exercises = part.replace('준비운동', '').split(',')
            exercise_dict['준비운동'].extend([exercise.strip() for exercise in exercises])
        elif '본운동' in part:
            exercises = part.replace('본운동', '').split(',')
            exercise_dict['본운동'].extend([exercise.strip() for exercise in exercises])
        elif '마무리운동' in part:
            exercises = part.replace('마무리운동', '').split(',')
            exercise_dict['마무리운동'].extend([exercise.strip() for exercise in exercises])
    return exercise_dict

# Apply the function to the DataFrame
df['Exercise_PRSCRPTN'] = df['Exercise_PRSCRPTN'].apply(process_exercises)

# Function to get the most common exercises for each cluster
def get_most_common_exercises(cluster_data):
    prepare_exercises = Counter()
    main_exercises = Counter()
    finish_exercises = Counter()
    
    for exercises in cluster_data:
        prepare_exercises.update(exercises['준비운동'])
        main_exercises.update(exercises['본운동'])
        finish_exercises.update(exercises['마무리운동'])
    
    return {
        '준비운동': prepare_exercises.most_common(3),
        '본운동': main_exercises.most_common(3),
        '마무리운동': finish_exercises.most_common(3)
    }

# Group by clusters and get the most common exercises for each cluster
cluster_exercises = df.groupby('clusters')['Exercise_PRSCRPTN'].apply(get_most_common_exercises)

# Convert the result to a DataFrame
cluster_exercises_df = pd.DataFrame(cluster_exercises.tolist(), index=cluster_exercises.index)

# Save the result to a CSV file
output_file_path = 'most_common_exercises_by_cluster.csv'
cluster_exercises_df.to_csv(output_file_path, encoding='utf-8-sig')

# # Display the first 20 rows of the modified DataFrame
# print(df.head(20))
# print(cluster_exercises_df.head())