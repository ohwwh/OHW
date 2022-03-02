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
        while (i < -index)
        {
            lst = lst -> prev;
            i ++;
        }
    }
    return (lst);
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

void	swap(int *a, int *b)
{
    int	temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void print2(int *arr, t_list **lstA)
{
    if (arr[0] > arr[1])
    {
        printf("sa\n");
        swap_stack(lstA);
    }
    else
        return ;
}

void print3(int *arr, t_list **lstA)
{
    if (arr[0] <= arr[1] && arr[1] <= arr[2])
        return ;
    else if (arr[0] <= arr[2] && arr[2] <= arr[1])
    {
        printf("sa\n");
        swap_stack(lstA);
        printf("ra\n");
        rotate(lstA);
    }
    else if (arr[1] <= arr[0] && arr[0] <= arr[2])
    {
        printf("sa\n");
        swap_stack(lstA);
    }
    else if (arr[1] <= arr[2] && arr[2] <= arr[0])
    {
        printf("ra\n");
        rotate(lstA);
    }
    else if (arr[2] <= arr[0] && arr[0] <= arr[1])
    {
        printf("rra\n");
        reverse_rotate(lstA);
    }
    else if (arr[2] <= arr[1] && arr[1] <= arr[0])
    {
        printf("sa\n");
        printf("rra\n");
        swap_stack(lstA);
        reverse_rotate(lstA);
    }
}

void    print(int i, int j, int size, t_list **lstA, t_list **lstB)
{
    int k;

    k = 0;
    while (k < i)
    {
        printf("ra\n");
        rotate(lstA);
        k ++;
    }
    if (j - i == 1)
    {
        printf("sa\n");
        swap_stack(lstA);
    }
    else if (j - i == size - 1)
    {
        printf("rra\n");
        reverse_rotate(lstA);
        printf("sa\n");
        swap_stack(lstA);
        printf("ra\n");
        rotate(lstA);
    }
    else
    {
        printf("pb\n");
        push((*lstA) -> content, lstB);
        pop(lstA);
        k = 0;
        while (k < j - i - 1)
        {
            printf("ra\n");
            rotate(lstA);
            k ++;
        }
        printf("pb\n");
        push((*lstA) -> content, lstB);
        pop(lstA);
        printf("sb\n");
        swap_stack(lstB);
        printf("pa\n");
        push((*lstB) -> content, lstA);
        pop(lstB);
        k = 0;
        while (k < j - i - 1)
        {
            printf("rra\n");
            reverse_rotate(lstA);
            k ++;
        }
        printf("pa\n");
        push((*lstB) -> content, lstA);
        pop(lstB);
    }
    k = 0;
    while (k < i)
    {
        printf("rra\n");
        reverse_rotate(lstA);
        k ++;
    }
}

void    print_reverse(int i, int j, int size, t_list **lstA, t_list **lstB)
{
    int k;

    k = 0;
    while (k < size - j)
    {
        printf("rra\n");
        reverse_rotate(lstA);
        k ++;
    }
    if (j - i == 1)
    {
        printf("rra\n");
        reverse_rotate(lstA);
        printf("sa\n");
        swap_stack(lstA);
        printf("ra\n");
        rotate(lstA);
    }
    else
    {
        printf("pb\n");
        push((*lstA) -> content, lstB);
        pop(lstA);
        k = 0;
        while (k < j - i)
        {
            printf("ra\n");
            rotate(lstA);
            k ++;
        }
        printf("pb\n");
        push((*lstA) -> content, lstB);
        pop(lstA);
        printf("sb\n");
        swap_stack(lstB);
        printf("pa\n");
        push((*lstB) -> content, lstA);
        pop(lstB);
        k = 0;
        while (k < j - i)
        {
            printf("rra\n");
            reverse_rotate(lstA);
            k ++;
        }
        printf("pa\n");
        push((*lstB) -> content, lstA);
        pop(lstB);
    }
    k = 0;
    while (k < size - j)
    {
        printf("ra\n");
        rotate(lstA);
        k ++;
    }
}

void    print_swap(int i, int j, int size, t_list **lstC, t_list **lstD)
{
    if (size < 2 | i == j)
        return ;
    if ((i + j) / 2 <= size / 2)
        print(i, j, size, lstC, lstD);
    else
        print_reverse(i, j, size, lstC, lstD);
}

void	sort(int *tab, int le, int re)
{
    int	pivot;
    int	left;
    int	right;

    if (le >= re)
        return ;
    pivot = tab[le];
    left = le + 1;
    right = re;
    while (left <= right)
    {
        while (left <= right && tab[right] >= pivot)
            right --;
        while (left <= right && tab[left] <= pivot)
            left ++;
        if (left <= right)
            swap(&tab[left], &tab[right]);
    }
    swap(&tab[le], &tab[right]);
    sort(tab, le, right - 1);
    sort(tab, right + 1, re);
}

void	sort2(int *tab, int le, int re, t_list **lstC, t_list **lstD, int size)
{
    int	pivot;
    int	left;
    int	right;

    if (le >= re)
        return ;
    pivot = tab[le];
    left = le + 1;
    right = re;
    while (left <= right)
    {
        while (left <= right && tab[right] >= pivot)
            right --;
        while (left <= right && tab[left] <= pivot)
            left ++;
        if (left <= right)
        {
            swap(&tab[left], &tab[right]);
            print_swap(left, right, size, lstC, lstD);
        }
    }
    swap(&tab[le], &tab[right]);
    print_swap(le, right, size, lstC, lstD);
    sort2(tab, le, right - 1, lstC, lstD, size);
    sort2(tab, right + 1, re, lstC, lstD, size);
}

void	ft_sort_int_tab(int *tab, int size)
{
    sort(tab, 0, size - 1);
}

void	print_quicksort(int *tab, t_list **lstC, t_list **lstD, int size)
{
    sort2(tab, 0, size - 1, lstC, lstD, size);
}

void print_greedy(int *arr, t_list **lstA, t_list **lstB, int size)
{
    int i;
    int j;

    i = 1;
    j = 1;
    if (size == 2)
        print2(arr, lstA);
    else if (size == 3)
        print3(arr, lstA);
    else
    {
        printf("pb\n");
        push((*lstA) -> content, lstB);
        pop(lstA);
        print_greedy(arr + 1, lstA, lstB, size - 1);
        ft_sort_int_tab(arr + 1, size - 1);
        while ((i < size) && (arr[i] < arr[0]))
            i ++;
        while ((j < size) && (arr[size - j] > arr[0]))
            j ++;
        if (i <= j)
        {
            j = i;
            while (j > 1)
            {
                printf("ra\n");
                rotate(lstA);
                j --;
            }
            printf("pa\n");
            push((*lstB) -> content, lstA);
            pop(lstB);
            while (i > 1)
            {
                printf("rra\n");
                reverse_rotate(lstA);
                i --;
            }
        }
        else
        {
            i = j;
            while (j > 1)
            {
                printf("rra\n");
                reverse_rotate(lstA);
                j --;
            }
            printf("pa\n");
            push((*lstB) -> content, lstA);
            pop(lstB);
            while (i > 0)
            {
                printf("ra\n");
                rotate(lstA);
                i --;
            }
        }
    }
}

int count(t_list *lstA, int num, int sizeA) //num을 lstA에 정렬해서 끼워넣기 위해,  lstA를 몇번 회전 시켜야 하는가?
{
    int i;
    int j;
    t_list *org;

    org = lstA;
    i = 1;
    j = 1;
    while (num > lstA -> content)
    {
        lstA = lstA -> next;
        i ++;
        if (i > sizeA)
            break ;
    }
    lstA = org -> prev;
    while (num < lstA -> content)
    {
        lstA = lstA -> prev;
        j ++;
        if (j > sizeA)
            break ;
    }
    if (2 * i + 1 <= 2 * j + 2)
        return (i);
    else
        return (-j);
}

int opt(t_list *lstA, t_list *lstB, int sizeA, int sizeB) //lstB에서 몇번째 인덱스에 있는 원소가 가장 적은 명령어 갯수를 가지면서 lstA로 옮겨질 수 있는가
{
    int min1;
    int i;
    int min2;
    int j;
    int k;
    int m;

    i = 0;
    min1 = 9999;
    min2 = 9999;
    while (1)
    {
        m = count(lstA, lstB -> content, sizeA);
        if (m >= 0 && m != 1)
            m = bigger(m - 1, i) + m - 1;
        else
            m = 2 * abs(m) - 1 + i;
        if (m < min1)
        {
            min1 = m;
            j = i;
        }
        lstB = lstB -> next;
        if (i >= sizeB)
            break;
        i ++;
    }
    i = 1;
    while (1)
    {
        m = count(lstA, lstB -> content, sizeA);
        if (m < 0)
            m = bigger(abs(m) - 1, i) + abs(m) - 1;
        else
            m = 2 * m - 1 + i;
        if (m < min2)
        {
            min2 = m;
            k = i;
        }
        lstB = lstB -> prev;
        if (i - 1 >= sizeB)
            break;
        i ++;
    }
    if (min1 <= min2)
        return (j);
    else
        return (-k);
}

void print_greedy2(int *arr, t_list **lstA, t_list **lstB, int sizeA, int sizeB)
{
    int i;
    int j;
    int k;

    k = 0;
    if (sizeA == 2)
        print2(arr, lstA);
    else if (sizeA == 3)
        print3(arr, lstA);
    else
    {
        printf("pb\n");
        push((*lstA) -> content, lstB);
        pop(lstA);
        print_greedy2(arr + 1, lstA, lstB, sizeA - 1, sizeB + 1);
        i = opt(*lstA, *lstB, sizeA - 1, sizeB + 1);
        j = count(*lstA, search(*lstB, i) -> content, sizeA - 1);






        if (i >= 0 && j != 0)
        {
            if (j >= 0)
            {
                while (k < smaller(i, j))
                {
                    printf("rr\n");
                    rotate(lstA);
                    rotate(lstB);
                    k ++;
                }
                if (i <= j)
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
                while (k < abs(j) - 1)
                {
                    printf("rra\n");
                    reverse_rotate(lstA);
                    k ++;
                }
            }
        }
        else if (j != 0)
        {
            if (j < 0)
            {
                while (k < abs(bigger(i, j + 1)))
                {
                    printf("rrr\n");
                    reverse_rotate(lstA);
                    reverse_rotate(lstB);
                    k ++;
                }
                if (i >= j + 1)
                {
                    while (k < abs(j + 1))
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
                    printf("rrB\n");
                    reverse_rotate(lstB);
                    k ++;
                }
                k = 0;
                while (k < j)
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
        if (j == 0)
        {
            printf("sa\n");
            swap_stack(lstA);
        }








        k = 0;
        if (j >= 0 && j != 0)
        {
            while (k < j)
            {
                printf("rra\n");
                reverse_rotate(lstA);
                k ++;
            }
        }
        else if (j != 0)
        {
            k = 0;
            while (k < abs(j))
            {
                printf("ra\n");
                rotate(lstA);
                k ++;
            }
        }
    }
}

void main1(t_list *lstA, t_list *lstB)
{
    srand(time(0));
    int arrr[5];
    for (int i = 0; i < 5; i ++)
        arrr[i] = rand() % 100;
    int arr1[5] = {14, 70, 73, 93, 81};
    int arr[4] = {2,3,1,4};
    printf("%d, %d, %d, %d, %d\n", arrr[0], arrr[1], arrr[2], arrr[3], arrr[4]);
    //print_greedy(arrr, lstA, lstB, 5);
    ft_sort_int_tab(arrr, 5);
    printf("%d, %d, %d, %d, %d\n", arrr[0], arrr[1], arrr[2], arrr[3], arrr[4]);
    /*printf("%d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3]);
    print_greedy(arr, 4);
    printf("%d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3]);*/
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
        /*j = rand() % 5;
        arr[argc - 2 - i] = j;
        push(j, &A);*/
        j = 0;
        while (j < i)
        {
            if (arr[argc - 2 - j] == arr[argc - 2 - i])
                return (0);
            j ++;
        }
        i ++;
    }
    //main1(A, B);
    print_stack(A);
    printf("\n");
    print_greedy2(arr, &A, &B, argc - 1, 0);
    //print_quicksort(arr, &A, &B, 10);
    print_stack(A);
    printf("\n");
}

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int	n = atoi(argv[1]);
    int	arr[n];
    int	j;

    srand(time(0));
    for (int i = 0; i < n; i ++)
    {
        j = rand() % 100;
        arr[i] = j;
        j = 0;
        while (j < i)
        {
            if (arr[j] == arr[i])
            {
                i --;
                break;
            }
            j ++;
        }
    }
    for (int i = 0; i < n; i ++)
    {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(" ");
    }
}*/
