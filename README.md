# VideoRental

<문제2>
    문제 1을 수행하신뒤,
        1> 코드의 문제점을 자유롭게 기술하신뒤 개선방향을 제시해주세요.
        2> 기술한 내용을 바탕으로 구현해주세요.

< ANS >
해당 프로그램은 기능적으로 영화를 대여하고 영수증을 발급할 수 있는 프로그램임.
아래와 같은 수정사항을 적용하여 해당 프로그램을 유지/보수가 용이하며 추후 보완 사항이 생길 경우 적용이 쉽도록 함. 

        [개선사항]
        Improvement[1] : Rental과 Movie Class의 캡슐화를 통해 추후 보완시 확장이 쉽도록 함.
        Improvement[2] : 함수들을 해당하는 객체로 이동하여 유지보수가 쉽도록 함.
        Improvement[3] : inline 함수를 활용하여 실행속도 개선.
        Improvement[4] : 코드 가독성 향상을 위한 코드 정리(미사용 함수 삭제, 범위 반복문, namespace, 함수/변수명 수정.

        [수정내역]
        Refactoring[1] : -. iterator 삭제 후 범위기반의 반복문 적용하여 코드의 가독성 향상.
                         -. 대여로를 계산하는 switch-case문을 함수로 추출하여 그 기능을 Rental 객체에서 수행하도록 함수 이동.
        Refactoring[2] : -. 포인트를 계산하는 구문을 함수로 추출하여 그 기능을 Rental 객체에서 수행하도록 함수 이동.
        
        Refactoring[3] : -. namespace 사용하여 코드의 가독성 향상.
                         -. 영수증을 생성하는 구문을 함수로 추출함.
                         -. ostringstream 삭제.
        Refactoring[4] : -. addRental 함수에 파라미터를 추가하여 main문 간결화.
        Refactoring[5] : -. Movie 캡슐화를 통해 Movie 객체에서 대여로를 계산하도록함 .
        Refactoring[6] : -. Movie 캡슐화를 통해 Movie 객체에서 포인트를 계산하도록함.
        Refactoring[7] : -. Movie.cpp 파일 삭제, Customer 미사용 생성자 및 함수 삭제 및 코드 정리.
        
        [추후과정] : 영화의 장르가 더욱 세분화 될 경우, Movie 클래스를 상속받는 세부 장르의 class를 생성하여 확장이 쉽도록 변경 할것.
        
