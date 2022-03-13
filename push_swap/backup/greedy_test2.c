#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int abs(int x)
{
    if (x < 0)
        return (-x);
    else
        return (x);
}

int bigger(int x, int y)
{
    if (x >= y)
        return (x);
    else
        return (y);
}

int smaller(int x, int y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

typedef struct s_list
{
    int	content;
    struct s_list	*next;
    struct s_list	*prev;
}t_list;

t_list	*createNode(int num)
{
    t_list	*lst;

    lst = (t_list *)malloc(sizeof(t_list));
    if (!lst)
        return (0);
    lst -> content = num;
    lst -> next = lst;
    lst -> prev = lst;
    return (lst);
}

void print_stack(t_list *lst)
{
    t_list  *head;

    head = lst;
    while(lst -> next != head)
    {
        printf("%d ", lst -> content);
        lst = lst -> next;
    }
    printf("%d ", lst -> content);
}

/*t_list	*createList(void)
{
    t_list	*head;
    return (head);
}*/

int	push(int num, t_list **lst)
{
    t_list	*newNode;

    newNode = createNode(num);
    if (!newNode)
        return (0);
    if(*lst)
    {
        newNode -> next = *lst;
        newNode -> prev = (*lst) -> prev;
        (*lst) -> prev -> next = newNode;
        (*lst) -> prev = newNode;
    }
    *lst = newNode;
    return (1);
}

int	pop(t_list **lst)
{
    t_list *delNode;

    if(*lst == 0)
        return (0);
    delNode = *lst;
    (*lst) -> next -> prev = (*lst) -> prev;
    (*lst) -> prev -> next = (*lst) -> next;
    *lst = (*lst) -> next;
    free(delNode);
    delNode = 0;
    return (1);
}

int	swap_stack(t_list **lst)
{
    t_list	*sec;

    if ((*lst == 0) | ((*lst) -> next == *lst))
        return (0);
    sec = (*lst) -> next;
    (*lst) -> next = sec -> next;
    sec -> next -> prev = *lst;
    sec -> next = *lst;
    sec -> prev = (*lst) -> prev;
    (*lst) -> prev -> next = sec;
    (*lst) -> prev = sec;
    (*lst) = sec;
    return (1);
}

void	rotate(t_list **lst)
{
    *lst = (*lst)->next;
}

void	reverse_rotate(t_list **lst)
{
    *lst = (*lst) -> prev;
}

int get_size(t_list *lst)
{
    int     size;
    t_list  *org;

    size = 0;
    org = lst;
    while (1)
    {
        lst = lst -> next;
        size ++;
        if (lst -> next == org)
            break ;
    }
    return (size);
}

t_list  *search(t_list *lst, int index)
{
    int i;

    i = 0;
    if (index >= 0)
    {
        while (i < index)
        {
            lst = lst -> next;
            i ++;
        }
    }
    else
    {
        //lst = lst -> prev;
        while (i < -index)
        {
            lst = lst -> prev;
            i ++;
        }
    }
    return (lst);
}

int is_sorted(t_list *lst, int size)
{
    int     i;
    int     j;
    t_list  *temp;

    i = 1;
    j = 1;
    temp = lst -> prev;
    while (lst -> content <= lst -> next -> content)
    {
        lst = lst -> next;
        i ++;
    }
    if (i == size)
        i = 0;
    return (i);
}

int check_sort(t_list *lst)
{
    t_list  *org;

    org = lst;
    while (lst -> next -> content >= lst -> content)
    {
        lst = lst -> next;
        if (lst -> next == org)
            return (1);
    }
    return (-1);
}

void print2(t_list **lstA)
{
    if ((*lstA) -> content > (*lstA) -> next -> content)
    {
        printf("sa\n");
        swap_stack(lstA);
    }
    else
        return ;
}

void print3(t_list **lstA)
{
    if ((*lstA) -> content <= (*lstA) -> next -> content && (*lstA) -> next -> content <= (*lstA) -> prev -> content)
        return ;
    else if ((*lstA) -> content <= (*lstA) -> prev -> content && (*lstA) -> prev -> content <= (*lstA) -> next -> content)
    {
        printf("sa\n");
        swap_stack(lstA);
        printf("ra\n");
        rotate(lstA);
    }
    else if ((*lstA) -> next -> content <= (*lstA) -> content && (*lstA) -> content <= (*lstA) -> prev -> content)
    {
        printf("sa\n");
        swap_stack(lstA);
    }
    else if ((*lstA) -> next -> content <= (*lstA) -> prev -> content && (*lstA) -> prev -> content <= (*lstA) -> content)
    {
        printf("ra\n");
        rotate(lstA);
    }
    else if ((*lstA) -> prev -> content <= (*lstA) -> content && (*lstA) -> content <= (*lstA) -> next -> content)
    {
        printf("rra\n");
        reverse_rotate(lstA);
    }
    else if ((*lstA) -> prev -> content <= (*lstA) -> next -> content && (*lstA) -> next -> content <= (*lstA) -> content)
    {
        printf("sa\n");
        printf("rra\n");
        swap_stack(lstA);
        reverse_rotate(lstA);
    }
}

int count_A(t_list *lstA, int num, int sizeA, int state) //num을 현재 위치가 state인 lstA에 정렬해서 끼워넣기 위해, lstA를 몇번 회전 시켜야 하는가?
// 맨 앞에서부터 1, 2, 3 ; 맨 뒤에서 부터 -1, -2, -3
{
    int i;
    int j;
    t_list *temp;

    lstA = search(lstA, state);
    temp = lstA -> prev;
    i = 0;
    j = 0;
    while (num > lstA -> content)
    {
        lstA = lstA -> next;
        i ++;
        if (i >= sizeA)
            break ;
    }
    lstA = temp;
    while (num < lstA -> content)
    {
        lstA = lstA -> prev;
        j ++;
        if (j >= sizeA)
            break ;
    }
    i = (i + state) % sizeA;
    j = (j + sizeA - state) % sizeA;
    if (i <= j)
        return (i);
    else
        return (-j);
}

int count_all(int count_A, int count_B, int reverse)
{
    int ret;

    if (reverse == 0)
    {
        if (count_A >= 0 && count_A != 1)
            ret = bigger(count_A, count_B) + 1;
        else if (count_A == 1)
            ret = count_B + 2;
        else
            ret = abs(count_A) + count_B + 1;
    }
    else
    {
        if (count_A < 0)
            ret = bigger(abs(count_A), count_B) + 1;
        else
            ret = count_A + count_B + 1;
    }
    return (ret);
}

int opt(t_list *lstA, t_list *lstB, int sizeA, int sizeB, int state) //lstB에서 몇번째 인덱스에 있는 원소가 가장 적은 명령어 갯수를 가지면서 lstA로 옮겨질 수 있는가
{                                                         //앞에서부터 셀 때는 0,1,2 ; 뒤에서 부터 셀 때는 -1,-2,-3 ;
    int min1;
    int i;
    //int min2;
    int j;
    //int k;
    int m;

    i = 0;
    min1 = 9999;
    //min2 = 9999;
    while (1)
    {
        if (i >= sizeB)
            break;
        m = count_all(count_A(lstA, lstB -> content, sizeA, state), i, 0);
        if (m < min1)
        {
            min1 = m;
            j = i;
        }
        lstB = lstB -> next;
        i ++;
    }
    i = 1;
    lstB = lstB -> prev;
    while (1)
    {
        if (i - 1 >= sizeB)
            break;
        m = count_all(count_A(lstA, lstB -> content, sizeA, state), i, 1);
        if (m < min1)
        {
            min1 = m;
            j = -i;
        }
        lstB = lstB -> prev;
        i ++;
    }
    /*if (min1 <= min2)
        return (j);
    else
        return (-k);*/
    return (j);
}

void print_greedy2(t_list **lstA, t_list **lstB, int sizeA, int sizeB)
{
    int i;
    int j;
    int k;

    k = 0;
    if (sizeA == 2)
        print2(lstA);
    else if (sizeA == 3)
        print3(lstA);
    else
    {	
		/*if (check_sort((*lstA) -> next) == -1)
		{
			printf("pb\n");
			push((*lstA) -> content, lstB);
			pop(lstA);
			print_greedy2(lstA, lstB, sizeA - 1, sizeB + 1);

		}*/
		if (check_sort((*lstA) -> next) != -1)
			return ;
		printf("pb\n");
		push((*lstA) -> content, lstB);
		pop(lstA);
		print_greedy2(lstA, lstB, sizeA - 1, sizeB + 1);
        //printf("\n");
        i = opt(*lstA, *lstB, sizeA - 1, sizeB + 1, is_sorted(*lstA, sizeA - 1));
        j = count_A(*lstA, search(*lstB, i) -> content, sizeA - 1, is_sorted(*lstA, sizeA - 1));

        if (i >= 0)
        {
            if (j >= 0)
            {
                while (k < smaller(i, j) && j != 1)
                {
                    printf("rr\n");
                    rotate(lstA);
                    rotate(lstB);
                    k ++;
                }
                if (i <= j && j != 1)
                {
                    while (k < j)
                    {
                        printf("ra\n");
                        rotate(lstA);
                        k ++;
                    }
                }
                else
                {
                    while (k < i)
                    {
                        printf("rb\n");
                        rotate(lstB);
                        k ++;
                    }
                }
            }
            else
            {
                k = 0;
                while (k < i)
                {
                    printf("rb\n");
                    rotate(lstB);
                    k ++;
                }
                k = 0;
                while (k < abs(j))
                {
                    printf("rra\n");
                    reverse_rotate(lstA);
                    k ++;
                }
            }
        }
        else
        {
            if (j < 0)
            {
                while (k < abs(bigger(i, j)))
                {
                    printf("rrr\n");
                    reverse_rotate(lstA);
                    reverse_rotate(lstB);
                    k ++;
                }
                if (i >= j)
                {
                    while (k < abs(j))
                    {
                        printf("rra\n");
                        reverse_rotate(lstA);
                        k ++;
                    }
                }
                else
                {
                    while (k < abs(i))
                    {
                        printf("rrb\n");
                        reverse_rotate(lstB);
                        k ++;
                    }
                }
            }
            else
            {
                k = 0;
                while (k < abs(i))
                {
                    printf("rrb\n");
                    reverse_rotate(lstB);
                    k ++;
                }
                k = 0;
                while (k < j && j != 1)
                {
                    printf("ra\n");
                    rotate(lstA);
                    k ++;
                }
            }
        }
        printf("pa\n");
        push((*lstB) -> content, lstA);
        pop(lstB);
        if (j == 1)
        {
            printf("sa\n");
            swap_stack(lstA);
        }
    }
}


void final(t_list **A, int size)
{
    int i;
    int j;

    i = 0;
    j = is_sorted(*A, size);
    if (size / 2 < j)
    {
        j = size - j;
        while (i < j)
        {
            printf("rra\n");
            reverse_rotate(A);
            i ++;
        }
    }
    else
    {
        while (i < j)
        {
            printf("ra\n");
            rotate(A);
            i ++;
        }
    }
}

int main(int argc, char *argv[])
{
    //argc = 101;
    int arr[argc - 1];
    int i;
    int j;
    t_list  *A;
    t_list  *B = 0;

    srand(time(0));
    i = 0;
    while (i < argc - 1)
    {
        j = atoi(argv[argc - 1 - i]);
        arr[argc - 2 - i] = j;
        push(j, &A);
       /* j = rand() % 10;
        arr[argc - 2 - i] = j;
        push(j, &A);*/

        j = 0;
        while (j < i)
        {
            if (arr[argc - 2 - j] == arr[argc - 2 - i])
            {
                i --;
                pop(&A);
                break ;
            }
            j ++;
        }
        i ++;
    }
    //print_stack(A);
    //printf("\n");
    print_greedy2(&A, &B, argc - 1, 0);
    //printf("\n");
    final(&A, argc - 1);
    //printf("\n");
    /*if (check_sort(A) == 1)
        printf("OK\n");
    else
        printf("KO\n");
    print_stack(A);
    printf("\n");*/
}
