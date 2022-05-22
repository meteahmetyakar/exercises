import pandas as pd
import matplotlib.pyplot as plt


#### Q1 ####

#reading csv file
df = pd.read_csv("company_sales_data.csv")

#fetching lists
profitList = df['total_profit'].tolist()
monthList  = df['month_number'].tolist()

#setting plot
plt.plot(monthList, profitList, 'r:', label = 'your_name, 64210067', marker="D")

plt.xticks(monthList)
plt.xlabel('Month Number')

plt.yticks([100000, 200000, 300000, 400000, 500000])
plt.ylabel('Total Profit')

plt.legend(loc='upper left')
plt.title('Company profit per month')
plt.show()


#### Q2 ####

#fetching lists
monthList  = df['month_number'].tolist()
faceCreamSalesData   = df['facecream'].tolist()
faceWashSalesData   = df['facewash'].tolist()

#setting plot
plt.bar([a-0.20 for a in monthList], faceCreamSalesData, width= 0.25, label = 'Face Cream sales data', align='edge')
plt.bar([a+0.20 for a in monthList], faceWashSalesData, width= -0.25, label = 'Face Wash sales data', align='edge')

plt.xticks(monthList)
plt.xlabel('Month Number')

plt.ylabel('Sales units in number')

plt.legend(loc='upper left')
plt.grid(True, linewidth= 1, linestyle="--")
plt.title('Facecream and facewash product sales data')
plt.show()


#### Q3 ####

#fetching lists
monthList  = df ['month_number'].tolist()
shampooSalesData   = df ['shampoo'].tolist()
moisturizerSalesData = df ['moisturizer'].tolist()

#defining subplots
f, axarr = plt.subplots(2, sharex=True)

#shampoo plot settings
axarr[0].plot(monthList, shampooSalesData, color = 'r', linestyle='-', label = 'Shampoo Sales Data', linewidth=3)
axarr[0].set_title('Sales data of  a Shampoo')
axarr[0].set_xlabel('Month Number')
axarr[0].set_ylabel('Sales units in number')
axarr[0].legend(loc='upper left')

#moisturizer plot settings
axarr[1].plot(monthList, moisturizerSalesData, color = 'g', linestyle=':', label = 'Moisturizer Sales Data', linewidth=3)
axarr[1].set_title('Sales data of  a Moisturizer')
axarr[1].set_xlabel('Month Number')
axarr[1].set_ylabel('Sales units in number')
axarr[1].legend(loc='upper left')

#plot and subplot settings
plt.xticks(monthList)
plt.subplots_adjust(left=0.1,
                    bottom=0.1,
                    right=0.9,
                    top=0.9,
                    wspace=0.4,
                    hspace=0.4)
plt.show()
