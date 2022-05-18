import pandas as pd
import numpy as np

#### Q1 ####
#a
s = pd.Series([7,11,13,17])
print(s)


#b
s1 = pd.Series(100.0,index=[0,1,2,3,4])
print(s1)

#c
s2 = pd.Series(np.random.randint(0, 100, size = 20))
print(s2)
s2.describe()

#d
temperatures = pd.Series([98.6,98.9,100.2,97.9],index=['Julie','Charlie','Sam','Andrea'])
print(temperatures)

#e
s3 = pd.Series({'Julie':98.6 ,'Charlie':98.9,'Sam':100.2,'Andrea':97.9})


#### Q2 ####

#a)
#definig the dictionary
D={
    'Maxine':[23,54,67],
    'James':[23,56,89],
    'Amanda':[56,43,24]
}

#Creating dataFrame
temparatures=pd.DataFrame(D)
#printing the dataframe 
print("a):")
print(temparatures)
print()

#b)
#Recreating the dataframe
temparatures=pd.DataFrame(D,index=["Morning","Afternoon","Evening"])
print("b):")
#printing the dataframe
print(temparatures)
print()

#c)
#Selecting the column maxine
print("c):")
c=temparatures[['Maxine']]
print(c)
print()

#d)
#Selecing the row Morning using the loc[] method
print("d):")
d=temparatures.loc[["Morning"],:]
print(d)
print()

#e)
#Selecting the rows for Morning and Evening using the loc[] method
print("e):")
e=temparatures.loc[["Morning","Evening"],:]
print(e)
print()

#f)
#Selecting the data under column Amanda and row Morning
print("f):")
f=temparatures[["Amanda"]].loc[["Morning"],:]
print(f)
print()

#g)
#selecting the data under columns Amanda,Maxine and rows Morning,Afternoon
print("g):")
g=temparatures[["Amanda","Maxine"]].loc[["Morning","Afternoon"]]
print(g)
print()

#h)
#Demonstrating the describe() method
print("h):")
h=temparatures.describe()
print(h)
print()

#i)
#Creating the transpose of the dataframe
print("i):")
i=temparatures.transpose()
print(i)
print()

#j)
#sorting the columns is nothing but reordering the columns we can use reorder() method and
#sorted() method top sort and reorder the columns
print("j):")
j=temparatures.reindex(sorted(temparatures.columns),axis=1)
print(j)
print()


#### Q3 ####
pd.set_option('display.max_rows', 500)
pd.set_option('display.max_columns', 500)


employees = pd.read_csv(r"EMPLOYEES.csv")

departments = pd.read_csv(r"DEPARTMENTS.csv")

job_history = pd.read_csv(r"JOB_HISTORY.csv")

jobs = pd.read_csv(r"JOBS.csv")

countries = pd.read_csv(r"COUNTRIES.csv")

regions = pd.read_csv(r"REGIONS.csv")

locations = pd.read_csv(r"LOCATIONS.csv")

#a
#print(departments)

#b
allRecordsCount = len(employees.index) + len(departments.index) + len(job_history.index) + len(jobs.index) + len(countries.index) + len(regions.index) + len(locations.index)
#print(allRecordsCount)

#c
result = employees.sort_values('first_name', ascending=False)

comment = """print("First Name      Last Name       Salary    Department Id:")
for index, row in result.iterrows():
    if(int(str(row['salary']).ljust(9)) > 10000):
        print(row['first_name'].ljust(15),row['last_name'].ljust(15),str(row['salary']).ljust(9),row['department_id'])


#d
values = {'commission_pct': 0}
result.fillna(value=values, inplace=True)
#print(result)

#e
print("First Name      Last Name       Salary    Department Id:")
for index, row in result.iterrows():
    if(row['department_id'] in [30,50,80]):
        print(row['first_name'].ljust(15),row['last_name'].ljust(15),str(row['salary']).ljust(9),row['department_id'])

#f"""
empt_dept = pd.merge(employees, departments, on=["department_id"])
#print(empt_dept)


#g
#print(empt_dept.agg({'salary': ['min', 'max', 'mean', 'median']}))
department_names = empt_dept['department_name'].unique()
df = pd.DataFrame()
department_names = np.sort(department_names)
print("Salaries")
print("Department Name      min     max     mean")
for names in department_names:
    df = empt_dept.loc[(empt_dept['department_name'] == names)]
    #print(df['salary'])
    al = df['salary']
    print(names.ljust(20) ,str(np.min(al)).ljust(7), str(np.max(al)).ljust(7), str(np.mean(al)).ljust(7))
    space = "           "
print(employees)
#print(empt_dept.groupby('country_id'))

#h

emp_loc = pd.merge(locations, empt_dept, on=["location_id"])
country_names = emp_loc['country_id'].unique()
country_names = np.sort(country_names)

print(emp_loc)

city_names = emp_loc['city'].unique()
city_names = np.sort(city_names)
result = pd.DataFrame([]);
for names in country_names:
    for cnames in city_names:
        sd = emp_loc.loc[(emp_loc['country_id'] == names) & (emp_loc['city'] == cnames)]
        salaries = sd['salary']

        lowSalary = np.array([])
        midSalary = np.array([])
        highSalary = np.array([])
        skySalary = np.array([])

        print(salaries)

        for x in salaries:
            if(0 <= x <= 5000):
               lowSalary = np.append(lowSalary, x)
            elif(5000 < x <= 10000):
                midSalary = np.append(midSalary, x)
            elif(10000< x <= 15000):
                highSalary = np.append(highSalary, x)
            elif(15000 < x <= 20500):
                skySalary = np.append(skySalary, x)

        lowMean = lowSalary.mean()
        midMean = midSalary.mean()
        highMean = highSalary.mean()
        skyMean = skySalary.mean()

        temp = pd.DataFrame({'low':lowMean, 'mis':midMean, 'high':highMean, 'sky':skyMean})
    #pd.concat([result, temp], keys = [names])

print(result)

            

print("3################")
print(country_names)