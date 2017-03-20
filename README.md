## 学生成绩管理系统
任务分配见wiki  

目标：  
1.  有不同类别的学生（本科生、硕士生和博士生）；  
2.  实现学生成绩的录入、显示、查询、修改和删除等功能。  
3.  要分科目的，查询可以展开好多功能，例如查具体科目成绩（来自助教）  

各表格  
student  
1. s\_id (primary key)  
2. psw  
3. s\_name  
4. s\_degree (本科生、硕士生、博士生 枚举)  

course  
1. course\_id (primary key)  
2. course\_name  

admin  
1. admin\_id (primary key)  
2. psw  
3. admin\_name

grade  
1. s\_id (foreign key)  
2. course\_id (foreign key)  
4. grade (int)  
使用phpmyadmin可以方便地创建数据库，及之后导入数据的功能，详见wiki
