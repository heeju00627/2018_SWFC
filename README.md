# 2018_SWFC
2018_SWFC

1. Git 설치 (Windows)
     a.	https://git-for-windows.github.io/에 접속하여 다운로드 및 설치
     b.	git bash 실행
     c.	작업할 디렉토리로 이동 (ex : $cd project)
     d.	git 사용자 설정
		$ git config --global user.name "name"
		$ git config --global user.email "email"
     e.	저장소 복제해서 작업 디렉토리 만들기
		$ git clone /로컬/저장소/경로


2. 작업 흐름
     a.	현재 git 관리 상태 확인
 		$ git status
     b.	현재 디렉토리에 있는 파일을 stage 영역으로 이동
 		$ git add .		(모든 추가/수정된 파일)
		$ git add filename	(특정 파일)
     c.	파일을 stage 영역에서 제거
		$ git rm --cached filename
     d.	stage 영역의 파일을 commit (Local repository에 저장)
		$ git commit -m "commit message"
     e.	commit된 내용을 push (Remote repository로 전송)
		$ git push origin master


3. 브랜치
독립개발 지원. commit을 이동할 수 있는 포인터 같은 것.
기본적으로 master 브랜치 만들어서 마지막 커밋을 가리킴.
master 브랜치는 개발이 완료되고 합쳐지는 곳이므로, 개개인 별 브랜치 생성해서 개발.
     a.	브랜치 생성
 		$ git branch branchname
     b.	브랜치 이동
 		$ git checkout branchname
     c.	브랜치 생성과 이동(checkout)을 한번에
		$ git checkout -b branchname
     d.	브랜치 확인
		$ git branch (*이 붙어있는 것이 현재 선택된 브랜치)
     e.	브랜치 병합 : 각각 commit을 진행했고, 서로 겹치게 수정한 파일이 없을 때
			master 브랜치로 병합하기 위한 명령어들
		$ git checkout master
		$ git merge branchname
     f.	브랜치 병합 취소(master branch에 대해) 수행 :
			충돌이 발생하여 취소하는 경우
		$ git reset --hard HEAD
			병합 이후에 병합 취소하는 경우
		$ git reset --hard ORIG_HEAD


4. 필요 명령어(cont.)
     a.	커밋 히스토리 조회
 		$ git log


5. 참고 사이트
https://backlog.com/git-tutorial/kr/
https://legacy.gitbook.com/book/mylko72/git/details