# get_next_line · 42 Seoul

> 파일 디스크립터에서 호출할 때마다 한 줄씩 읽어 반환하는 함수 `get_next_line(int fd)` 구현

## 개요
`read()`로 `BUFFER_SIZE`만큼씩 읽으면서 개행(`\n`)을 만날 때까지 줄을 이어 붙이고,
개행 뒤에 남은 데이터는 정적 버퍼에 보관해 다음 호출에서 이어 쓴다.
파일 끝이거나 오류가 나면 `NULL`을 반환한다.

## 구현 포인트
- 남은 데이터를 `static char remainder[OPEN_MAX][BUFFER_SIZE + 1]`에 fd별로 저장 → 여러 fd를 번갈아 읽어도 각 fd의 위치가 유지됨
- `remainder_find_n()`: 이전 호출에서 남은 버퍼에 개행이 있으면 `read` 없이 바로 한 줄을 만들어 반환
- `read_file()`: 개행이 나올 때까지 `read` → `find_newline()` → `ft_strjoin()`을 반복하고, 개행 뒤 나머지를 `remainder[fd]`로 복사
- `read_flag_check()`: 상태 값(`make_new_line`, `read_EOF`, `read_failed`)에 따라 줄을 반환하거나 해제 후 `NULL` 반환
- 상태 값은 `t_read_status`, `t_make_line_status` enum으로 정의
- 유틸 `ft_strjoin(s1, s2, size)`는 `s2`에서 `size`바이트만 붙이고 기존 `s1`을 해제

## 보너스
`get_next_line_bonus.c` / `get_next_line_utils_bonus.c` / `get_next_line_bonus.h`는 헤더 이름과
기본 `BUFFER_SIZE`(bonus 1024, mandatory 100000)만 다르고 로직은 동일하다. 다중 fd 지원은 mandatory에서 이미 처리한다.

## 빌드 & 사용
```bash
make            # get_next_line.c + get_next_line_utils.c → libgnl.a
```
`BUFFER_SIZE`는 컴파일 시점에 정해지므로, 값을 바꿔 테스트할 때는 소스를 직접 함께 컴파일한다.

```c
/* example.c */
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int   fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror example.c -L. -lgnl
# BUFFER_SIZE 지정
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 example.c get_next_line.c get_next_line_utils.c
# 보너스 파일로 빌드
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 example.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

저장소의 `main.c`는 여러 fd를 번갈아 읽는 테스트 코드이며, 테스트 파일 경로가 로컬 절대 경로로 되어 있어 실행 전 수정이 필요하다.

## 구조
```
get_next_line/
├── Makefile
├── get_next_line.c / .h           # mandatory
├── get_next_line_utils.c          # ft_strdup, ft_strjoin, ft_strlcpy, find_newline
├── get_next_line_bonus.c / .h     # bonus
├── get_next_line_utils_bonus.c
├── main.c                         # 테스트용
└── moby_dick.txt, test.txt, test2.txt, no_new_line.txt   # 테스트 입력
```

42 Seoul 공통 과정 과제.
