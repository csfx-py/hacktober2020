import os
import glob
import pandas as pd

# search all csv files start with numeric.
extension = 'csv'
csv_files = [i for i in glob.glob('[0-9]*.{}'.format(extension))]
print("Reading csv files : ")
print(csv_files)
if len(csv_files) == 0:
    print("No csv files found to process.")
else:
    # extracting id from all files in one.
    print("Extracting unique ID's from csv files...")
    col_list = ["id"]  # column name on which operation should happen
    id_csv = pd.concat([pd.read_csv(f, usecols=col_list) for f in csv_files])
    id_csv.rename(columns={'id': 'ride_id'}, inplace=True)  # rename column
    id_csv.drop_duplicates(subset=None, inplace=True)
    id_csv.to_csv('id.csv', index=False)
    print("Unique ID's extracted.")

    # reading id.csv to compare with csv files
    id_file = pd.read_csv('id.csv', sep=',', index_col=0)

    # creating dataframe with default value 0.
    res = pd.DataFrame(0, index=id_file.index, columns=csv_files)

    # now finding id in extracted csv files and if value found mark 1.
    print("Checking ID for Fraud in CSV files...")
    for f in csv_files:
        tmp = pd.read_csv(f, sep=',', index_col=1) #index_col in which column you want to search 
        res.loc[id_file.index.isin(tmp.index), f] = 1
        print(res)

    print("Creating results.csv...")
    #res.rename(columns={'c1_old': 'c1_new', 'c2_old': 'c2_new'}, inplace=True) #in case you want to rename headers.

    # writing results to csv
    res.to_csv('results.csv', sep=',')
    print("results.csv created.")

    # cleaning temp files.
    os.remove("id.csv")
