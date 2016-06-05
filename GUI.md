学生成绩管理系统GUI
====

****

*    [登录界面](#Login)
*    [学生界面](#Student)
*    [管理员界面](#Administrator)

****

<h2 id="Login">登录界面</h2>

![Login_screenshot](https://code.csdn.net/bu2_int/cpp-project/blob/master/screenshots/Login.png)

上图为登陆界面，用户名用于输入ID，密码用于输入Password（不回显），下面的单选按钮可以选择以学生身份(分为本科生、研究生、博士生)登录还是以管理员身份登录。按登录按钮登录，若用户名和密码正确，则进入学生界面或者管理员界面；否则会给出Warning，点击OK后用户名和密码都会清空，需重新输入。按退出按钮则直接退出程序。

![Warning1_screenshot](https://code.csdn.net/bu2_int/cpp-project/blob/master/screenshots/Warning-1.png)

<h2 id="Student">学生界面</h2>

![StudentMainWindow](https://code.csdn.net/bu2_int/cpp-project/blob/master/screenshots/StudentMainWindow.png)

上图为学生界面，学生登录后直接显示所有课程的分数，不可编辑，只能查看。按退出键退出程序。

<h2 id="Administrator">管理员界面</h2>

![AdminMainWindow](https://code.csdn.net/bu2_int/cpp-project/blob/master/screenshots/AdminMainWindow.png)

上图为管理员的主界面，管理员登录后不显示任何人的任何成绩。

![Find](https://code.csdn.net/bu2_int/cpp-project/blob/master/screenshots/Find.png)

点击查询会出现查询的界面，若两个输入框都不输入内容，则相当于不查询；若只有一个输入框有输入，则是单条件查询；若两个输入框内都有输入，则相当于双条件查询。

点击确定进行查询并显示出查询结果，点击取消则直接退出查询界面。

显示出成绩后可以右键选择编辑成绩或者删除成绩。注意这里的编辑成绩只能修改分数，其他信息不能修改。删除成绩时会提示确认。

![Warning2_screenshot](https://code.csdn.net/bu2_int/cpp-project/blob/master/screenshots/Warning-2.png)

![Add](https://code.csdn.net/bu2_int/cpp-project/blob/master/screenshots/Add.png)

点击添加会出现添加成绩界面，需要输入三条信息：学生学号、课程代码、成绩。这三条信息都必须输入，否则会弹出警告窗口。

<center>Copyright &copy; 2016 章世超 李博奥 徐帅 梁鹏. All Rights Reserved</center>

