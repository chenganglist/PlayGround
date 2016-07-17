 git clone git@121.48.175.198:/data/git/project.git    
等价于    
 git clone ssh://git@121.48.175.198:/data/git/LearningSummary.git    
    
 本地key-gen一个ssh密钥ssh-keygen -t rsa     
    
cat  ~/.ssh/id_rsa.pub    
复制到远程服务器上主目录/home/git/.ssh/authorized_keys   

一行一个用户     
    
####创建客户端登录证书    
    
注，收集所有需要登录的用户的公钥，就是他们自己生成的id_rsa.pub文件，把所有公钥复制到/home/git/.ssh/authorized_keys文件里，一行一个。    
客户端生成id_rsa.pub文件的命令    
  	    
$ ssh-keygen -t rsa    
$ cat  .ssh/id_rsa.pub    
ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEA6NwUHeNNi+PC6KlrcJrXXDmKxRMmgHIPp79sgX6zqfdSlmNj7rBPQeyEKS9Wg8yI6jd8aG2jsUx99Vjti2VK2vEXKkRHxwID7ri69gE71RfDtv6ekafnzLo14J8hAp0spMk+N3wEAQRYDmcYo1wmnm/jMBedGrHj4NJQ1vYy1hVtJasGMSzjcMrlz9qvaluWnQ5tQjKFQVVwKsRRRzs8qTvzVhLJt4NQ+CAN45tqfsRuf58Uba9QNK7/6xSUiIKXQiILz8PMGJ3MnlV+eN3wx2aeztdevxu9plggtG05SMmd8GNVzXrN1IaxXSvz0UwjQ2kygu7aCqO8AZWH49rouw== leo@LEO-PC  

ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCpNlLDiFt005noLq4u8jODUU/+Fiy7JYvwcRIRg/2/zaXU5i+LvwgxGgs01M79G0SIRtRKotRuk+b43VlgF3DxJi7oaBegFwzOVkI5DdRNfMTQctn0S6VvxFbUQdAzvkVmfMFPzNAX4HedlXwYgKnawmha6bjcbdeVmfbyom+9ufVeoPG6xCm5jkKWervvmE8s4rp7WtUcoJH2HUDTJ+uQaIZN1Wz2pfwu+znzN6MjSW/xi392NMUefAuMZALHFbNWF4egU5lWYNLn7RqQjitL8s1Mgy3nGPAFbopusnWpA62gh5gUdimIrBc2bUOGSD0Mwq+d8r2bii5cMjgAiGLp Chen@Chen-PC   

注，一路回车即可，将生成的id_rsa.pub，复制给管理员，帮你在服务器上增加一下，下次你用git时就不需要输入用户名和密码了。    
    
####查看服务器上authorized_keys文件    
  	    
[root@git ~]# cat /home/git/.ssh/authorized_keys    