# 2018_SWFC
2018_SWFC

1. Git ��ġ (Windows)
     a.	https://git-for-windows.github.io/�� �����Ͽ� �ٿ�ε� �� ��ġ
     b.	git bash ����
     c.	�۾��� ���丮�� �̵� (ex : $cd project)
     d.	git ����� ����
		$ git config --global user.name "name"
		$ git config --global user.email "email"
     e.	����� �����ؼ� �۾� ���丮 �����
		$ git clone /����/�����/���


2. �۾� �帧
     a.	���� git ���� ���� Ȯ��
 		$ git status
     b.	���� ���丮�� �ִ� ������ stage �������� �̵�
 		$ git add .		(��� �߰�/������ ����)
		$ git add filename	(Ư�� ����)
     c.	������ stage �������� ����
		$ git rm --cached filename
     d.	stage ������ ������ commit (Local repository�� ����)
		$ git commit -m "commit message"
     e.	commit�� ������ push (Remote repository�� ����)
		$ git push origin master


3. �귣ġ
�������� ����. commit�� �̵��� �� �ִ� ������ ���� ��.
�⺻������ master �귣ġ ���� ������ Ŀ���� ����Ŵ.
master �귣ġ�� ������ �Ϸ�ǰ� �������� ���̹Ƿ�, ������ �� �귣ġ �����ؼ� ����.
     a.	�귣ġ ����
 		$ git branch branchname
     b.	�귣ġ �̵�
 		$ git checkout branchname
     c.	�귣ġ ������ �̵�(checkout)�� �ѹ���
		$ git checkout -b branchname
     d.	�귣ġ Ȯ��
		$ git branch (*�� �پ��ִ� ���� ���� ���õ� �귣ġ)
     e.	�귣ġ ���� : ���� commit�� �����߰�, ���� ��ġ�� ������ ������ ���� ��
			master �귣ġ�� �����ϱ� ���� ��ɾ��
		$ git checkout master
		$ git merge branchname
     f.	�귣ġ ���� ���(master branch�� ����) ���� :
			�浹�� �߻��Ͽ� ����ϴ� ���
		$ git reset --hard HEAD
			���� ���Ŀ� ���� ����ϴ� ���
		$ git reset --hard ORIG_HEAD


4. �ʿ� ��ɾ�(cont.)
     a.	Ŀ�� �����丮 ��ȸ
 		$ git log


5. ���� ����Ʈ
https://backlog.com/git-tutorial/kr/
https://legacy.gitbook.com/book/mylko72/git/details