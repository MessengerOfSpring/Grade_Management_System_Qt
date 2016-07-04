学生成绩管理系统GUI
====

****

*    [登录界面](#Login)
*    [学生界面](#Student)
*    [管理员界面](#Administrator)

****

<h2 id="Login">登录界面</h2>

![Login_screenshot](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/Login.png)

[version2.0]增加本科生，硕士生，博士生，管理员登录的图标  
上图为登陆界面，用户名用于输入ID，密码用于输入Password（不回显），下面的单选按钮可以选择以学生身份(分为本科生、研究生、博士生)登录还是以管理员身份登录。按登录按钮登录，若用户名和密码正确，则进入学生界面或者管理员界面；否则会给出Warning，点击OK后用户名和密码都会清空，需重新输入。按退出按钮则直接退出程序。

![Warning1_screenshot](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/Warning-1.png)

<h2 id="Student">学生界面</h2>

![StudentMainWindow](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/StudentMainWindow.png)

上图为学生界面，学生登录后直接显示所有课程的分数，不可编辑，只能查看。按退出键退出程序。

<h2 id="Administrator">管理员界面</h2>

![AdminMainWindow](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/AdminMainWindow.png)
###注册
*[version2.0] 增加左侧“注册”菜单，点击后分别是管理员、本科生、硕士生、博士生注册菜单。同时增加查询、增加、退出的图标*    
上图为管理员的主界面，管理员登录后不显示任何人的任何成绩。
![AdminDlg](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/AdminDlg.png)
####管理员注册
上图为管理员注册界面
![Warning-ID(not null)](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/Warning-ID(not null).png)
#####账号不能为空

![Warning-Password(not null)](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/Warning-Password(not null).png)
#####密码不能为空

![Warning-Name(not null)](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/Warning-Name(not null).png)
#####名称不能为空

![Enroll-fail](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/Enroll-fail.png)
#####注册失败
上图为注册失败界面，对应相应语句插入数据库失败，可能原因有账号被占用等

![Enroll-success](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/Enroll-success.png)
#####注册成功
上图为注册成功界面，账号，密码，名称插入到数据库中

![UnderDlg](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/UnderDlg.png)
####本科生注册
其他功能与管理员类似，不过S_degree的值为undergraduate并插入到STUDENT表

![MasterDlg](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/MasterDlg.png)
####硕士生注册
其他功能与管理员类似，不过S_degree的值为Master并插入到STUDENT表

![PhdDlg](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/PhdDlg.png)
####博士生注册
其他功能与管理员类似，不过S_degree的值为Phd并插入到STUDENT表

###查询
![Find](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/Find.png)

点击查询会出现查询的界面，若两个输入框都不输入内容，则相当于不查询；若只有一个输入框有输入，则是单条件查询；若两个输入框内都有输入，则相当于双条件查询。

点击确定进行查询并显示出查询结果，点击取消则直接退出查询界面。

显示出成绩后可以右键选择编辑成绩或者删除成绩。注意这里的编辑成绩只能修改分数，其他信息不能修改。删除成绩时会提示确认。

![Warning2_screenshot](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/Warning-2.png)

###添加
![Add](https://code.csdn.net/bu2_int/grade_management_system_qt/blob/master/screenshots/Add.png)

点击添加会出现添加成绩界面，需要输入三条信息：学生学号、课程代码、成绩。这三条信息都必须输入，否则会弹出警告窗口。

<center>Copyright &copy; 2016 章世超 李博奥 徐帅 梁鹏. All Rights Reserved</center>

