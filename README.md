# 📚 우선순위 큐 기반 도서 관리 시스템 (Library Management System)

C언어의 동적 배열 할당과 자료구조(우선순위 큐)를 활용하여 구현한 도서 관리 프로그램입니다.
프로그램이 종료되어도 데이터가 유지되도록 파일 입출력(I/O) 기능을 포함하고 있습니다.

## ✨ 주요 기능
- **도서 등록 (Enqueue)**: 도서 번호 중복 검증 및 동적 배열 크기 자동 확장(`malloc`)
- **도서 검색 & 수정**: 버블 정렬(Bubble Sort) 알고리즘을 통한 도서 번호 기준 오름차순 자동 정렬 상태 유지
- **도서 삭제 (Dequeue)**: 배열 요소 시프트(Shift) 기반의 안전한 데이터 삭제
- **데이터 영속성 (File I/O)**: `fprintf`/`fscanf`를 활용한 프로그램 종료 시 자동 데이터 저장(`saveBook`) 및 실행 시 자동 불러오기(`loadBook`)

## 🛠️ 개발 환경 및 사용 기술
- **Language**: C (C11)
- **Data Structure**: Priority Queue (Dynamic Array-based implementation)
- **Concepts Used**: Structure (`struct`), Pointer (`->`), File Stream (`FILE*`)
