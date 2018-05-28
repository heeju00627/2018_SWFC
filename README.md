# 2018_SWFC
2018_SWFC

## 1. Git 설치 (Windows)
1.	https://git-for-windows.github.io/에 접속하여 다운로드 및 설치
2.	git bash 실행
3.	작업할 디렉토리로 이동 (ex : $cd project)
4.	git 사용자 설정
<pre><code>$ git config --global user.name "name"
$ git config --global user.email "email"</code></pre>
5.	저장소 복제해서 작업 디렉토리 만들기
<pre><code>$ git clone /로컬/저장소/경로</code></pre>


## 2. 작업 흐름
1.	현재 git 관리 상태 확인
<pre><code>$ git status</code></pre>
2.	현재 디렉토리에 있는 파일을 stage 영역으로 이동
<pre><code>$ git add . 	(모든 추가/수정된 파일)</code></pre>
<pre><code>$ git add filename (특정 파일)</code></pre>
3.	파일을 stage 영역에서 제거
<pre><code>$ git rm --cached filename</code></pre>
4.	stage 영역의 파일을 commit (Local repository에 저장)
<pre><code>$ git commit -m "commit message"</code></pre>
5.	commit된 내용을 push (Remote repository로 전송)
<pre><code>$ git push origin master</code></pre>


## 3. 브랜치
* 독립개발 지원
* commit을 이동할 수 있는 포인터 같은 것.
* 기본적으로 master 브랜치 만들어서 마지막 커밋을 가리킴.
* master 브랜치는 개발이 완료되고 합쳐지는 곳이므로, 개개인 별 브랜치 생성해서 개발.
1.	브랜치 생성
<pre><code>$ git branch branchname</code></pre>
2.	브랜치 이동
<pre><code>$ git checkout branchname</code></pre>
3.	브랜치 생성과 이동(checkout)을 한번에
<pre><code>$ git checkout -b branchname</code></pre>
4.	브랜치 확인
<pre><code>$ git branch (*이 붙어있는 것이 현재 선택된 브랜치)</code></pre>
5.	브랜치 병합 : 각각 commit을 진행했고, 서로 겹치게 수정한 파일이 없을 때
			master 브랜치로 병합하기 위한 명령어들
<pre><code>$ git checkout master
$ git merge branchname</code></pre>
6.	브랜치 병합 취소(master branch에 대해) 수행 :		
<pre><code>$ git reset --hard HEAD (충돌이 발생하여 취소하는 경우)</code></pre>
<pre><code>$ git reset --hard ORIG_HEAD (병합 이후에 병합 취소하는 경우)</code></pre>


## 4. 필요 명령어(cont.)
1.	커밋 히스토리 조회
<pre><code>$ git log</code></pre>


## 5. 참고 사이트
* https://backlog.com/git-tutorial/kr/
* https://legacy.gitbook.com/book/mylko72/git/details
