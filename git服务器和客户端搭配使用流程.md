git服务器和客户端搭配使用流程
第一步是在服务器上建仓库---存储机制有所不同
1、在服务器端创建git仓库
exclude

project.git/objects:
1c  5a  92  info  pack

project.git/objects/1c:
364adf14e4bc182142d66f043dde298aa5726a

project.git/objects/5a:
159accf8f013ec0df1ea6f9bb033e4946e4f30

project.git/objects/92:
c00a312cd52ff229b96af623ea810bbcd6ecf6

project.git/objects/info:

project.git/objects/pack:

project.git/refs:
heads  tags

project.git/refs/heads:
master

project.git/refs/tags:

2、在本地创建git仓库
修改代码后再进行同步和更新、推送与抓取


