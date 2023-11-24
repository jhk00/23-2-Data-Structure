#include <stdio.h>

typedef struct {
    int math;
    int korean;
    int english;
} Score;

double math_average(Score s1, Score s2, Score s3)
{
int sum = (double)(s1.math+s2.math+s3.math);
return sum/3;
}

void high_score(Score s1, int *max)
{
if(s1.math > s1.korean && s1.math > s1.english) *max = s1.math;
if(s1.korean > s1.math && s1.korean > s1.english) *max = s1.korean;
if(s1.english > s1.korean && s1.english > s1.math) *max = s1.english;

}

int main(void)
{
    Score a = {90, 80, 46}, b = {55, 67, 83}, c = {80, 39, 100};
    int score;
    double math_aver;

    printf("The average score of math is %lf\n", math_average(a, b, c));
    high_score(a, &score);
    printf("The student a's highest score is %d\n", score);
}