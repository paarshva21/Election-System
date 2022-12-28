#include <stdio.h>
struct candidate
{
    char name[100], branch[100];
    int age, c;
    long int sapid;
};
void main()
{
    struct candidate s[100], t;
    int i, j, k, n, p, C = 0;
    printf("\t\t\t\t\t\t");
    printf("\033[1;31m"); // set colour to red
    printf("Welcome to DJ Sanghvi Election Portal\n");
    printf("\033[0m"); // set colour to white
    printf("In the upcoming elections,students will be casting votes to elect respectively the College President, Vice-President and the Secretary of DJ Sanghvi College\n");
    printf("The candidate with most votes will be elected as President\n");
    printf("The candidate with second most votes will be elected as Vice-President\n");
    printf("The candidate with third most votes will be elected as Secretary\n");
    printf("Cast your vote wisely!\n");
    printf("Enter no. of candidates:\n");
    scanf("%d", &n);
    printf("Enter details of candidates as follows:\n");
    printf("Name\t Branch\t Age\t SAPID\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", s[i].name);
        scanf("%s", s[i].branch);
        scanf("%d", &s[i].age);
        scanf("%ld", &s[i].sapid);
    }
    printf("The eligible candidates are:\n");
    printf("Sr No.\t Name\t Branch\t Age\t SAPID\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d\t %s\t %s\t %d\t %ld\n", (i + 1), s[i].name, s[i].branch, s[i].age, s[i].sapid);
    }
    printf("Enter the number of eligible voters:\n");
    scanf("%d", &p);
    printf("Instructions for voting:\n");
    printf("To vote for Candidate 1,enter 1;\nTo vote for Candidate 2,enter 2;\nTo vote for Candidate 3,enter 3;\nAnd so on.\nTo cast NOTA vote,enter 0.\n");
    for (i = 0; i < p; i++)
    {
    VOTE:
    {
        printf("Cast your vote:\n");
        scanf("%d", &k);
    }
        if (k > n)
        {
            printf("Invalid vote cast\n");
            printf("Please go through the instructions to recast your vote\n");
            goto VOTE;
        }
        if (k == 0)
        {
            printf("NOTA Vote cast\n");
            C++;
        }
        for (j = 0; j < n; j++)
        {
            if (k == (j + 1))
            {
                printf("Vote for %s having SAPID:%ld cast\n", s[j].name, s[j].sapid);
                s[j].c++;
            }
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (s[j + 1].c > s[j].c)
            {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }
    printf("The final results of voting are:\n");
    printf("Sr No.\t Name\t Branch\t Age\t SAPID\t Votes recieved\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d\t %s\t %s\t %d\t %ld\t %d\n",
               (i + 1), s[i].name, s[i].branch, s[i].age, s[i].sapid, s[i].c);
    }
    printf(" %d\t NOTA\t None\t None\t None\t\t %d\n", (n + 1), C);
    printf("\033[1;31m"); // set colour to red
    printf("The new College President of DJ Sanghvi is %s having SAPID:%ld\n", s[0].name, s[0].sapid);
    printf("The new College Vice-President of DJ Sanghvi is %s having SAPID:%ld\n", s[1].name, s[1].sapid);
    printf("The new College Secretary of DJ Sanghvi is %s having SAPID:%ld\n", s[2].name, s[2].sapid);
    printf("\033[0m"); // set colour to white
    printf("Much congratulations to above candidates!");
}