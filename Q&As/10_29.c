#include <stdio.h>
#include <math.h>

struct Stu {
    int id;
    int kemu;
    double aver;
};

int main() {
    int n, i, j, k, sum, lin1, lin2, z = 0, x, lo;
    struct Stu stu[10000];
    struct Stu tmp;

    scanf("%d", &n);

    // 输入 n 位学生信息
    for (i = 0; i < n; i++) {
        sum = 0;
        scanf("%d %d", &lin1, &lin2);
        
        if (lin2 < 2) {
            for (int u = 0; u < lin2; u++) {
                scanf("%d", &lin1);
            }
            // 输入学生的课程数小于 2 门的学生不计入
            // 为了

        } else { // 输入学生的多门课成绩并求好平均数
            stu[z].id = lin1;
            stu[z].kemu = lin2;
            
            for (j = 0; j < stu[z].kemu; j++) {
                scanf("%d", &x);
                sum += x;
            }
            
            stu[z].aver = sum * 1.0 / stu[z].kemu;
            z++; // 重新计算保存有 2 门以上课程的学生
        }
    }

    if (z == 0) {
        printf("NO");
        return 0;
    } else {
        for (i = 0; i < z - 1; i++) {
            for (j = 0; j < z - 1 - i; j++) {
                if ((fabs(stu[j].aver - stu[j + 1].aver) < 1e-7 && stu[j].id > stu[j + 1].id) || stu[j].aver < stu[j + 1].aver) {
                    tmp = stu[j];
                    stu[j] = stu[j + 1];
                    stu[j + 1] = tmp;
                }
            }
        }

        for (i = 0; i < z; i++) {
            printf("%d-%.2lf\n", stu[i].id, (int)(stu[i].aver * 100) / 100.0);
        }
    }

    return 0;
}
