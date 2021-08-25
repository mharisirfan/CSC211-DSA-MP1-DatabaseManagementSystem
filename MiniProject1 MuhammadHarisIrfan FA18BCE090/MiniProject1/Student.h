///------------Muhammad Haris Irfan--FA18-BCE-090---------MINI PROJECT 1-----------------------------------------------------------------///
struct employee
{

 char first_name[20];
 char surname[20];
 int intake_year;
 char session[10];
 char program[10];
 int roll_no;
};

struct node
{

    struct employee data;

    struct node * next;
};
