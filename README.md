# C-Snake-main

C++ Snake Game 과제 - 제출용

### 시연 영상

[![Video Label](https://img.youtube.com/vi/nEZdDYl5kUg/0.jpg)](https://www.youtube.com/watch?v=nEZdDYl5kUg)

### 파일 구조
``` bash
📦C-Snake-main
┣ 📂UI # Vector와 String의 조합으로 UI를 text 형식으로 표현
┃ ┣ 📜defeat.h # 패배창 -> 적용은 못시킴
┃ ┣ 📜menu.h # 메뉴창 -> 적용은 못시킴
┃ ┗ 📜scoreboard.h # 스코어 보드 -> 5단계에 사용됨
┣ 📂include # interface
┃ ┣ 📂snake_entity # snake라는 개체를 생성하고 관리하는데 사용
┃ ┃ ┗ 📜snake_entity.h 
┃ ┣ 📂snake_game # snake game 시작하는데 사용
┃ ┃ ┗ 📜snake_game.h
┃ ┣ 📂snake_map_game # snake game의 맵을 관리하는데 사용
┃ ┃ ┗ 📜snake_map_game.h
┃ ┗ 📂snake_map_scoreboard # snake game의 스코어보드 및 미션을 관리하는데 사용
┃ ┃ ┗ 📜snake_map_scoreboard.h
┣ 📂map # stage들이 모여있는 폴더
┃ ┣ 📜stage1.h 
┃ ┣ 📜stage2.h
┃ ┣ 📜stage3.h
┃ ┗ 📜stage4.h
┣ 📂src # 실제 구현 부분
┃ ┣ 📂snake_entity # snake라는 개체를 생성하고 관리하는데 사용
┃ ┃ ┗ 📜snake_entity.cpp
┃ ┣ 📂snake_game # snake game 시작하는데 사용
┃ ┃ ┗ 📜snake_game.cpp
┃ ┣ 📂snake_item # snake game의 item들을 관리하는데 사용
┃ ┃ ┣ 📜snake_fast.cpp # fast -> tick을 줄여서 빠르게 움직이게 하는 아이템
┃ ┃ ┣ 📜snake_growth.cpp # growth -> snake의 body를 늘리도록 만드는 아이템
┃ ┃ ┣ 📜snake_item.cpp # snake의 전체적인 item을 관리하는데에 사용
┃ ┃ ┣ 📜snake_poison.cpp # poison -> snake의 body를 줄이도록 만드는 아이템
┃ ┃ ┗ 📜snake_slow.cpp # slow -> tick을 늘려서 느리게 움직이게 하는 아이템
┃ ┣ 📂snake_map_game # snake game의 맵을 관리하는데 사용
┃ ┃ ┗ 📜snake_map_game.cpp
┃ ┣ 📂snake_map_scoreboard # snake game의 스코어보드 및 미션을 관리하는데 사용
┃ ┃ ┗ 📜snake_map_scoreboard.cpp
┃ ┗ 📜main.cpp # main 코드가 존재하는 부분
┣ 📜.gitignore
┣ 📜Makefile # makefile 파일
┣ 📜README.md # 문서화
┗ 📜main # 실헹파일
```