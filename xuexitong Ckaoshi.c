#include <stdio.h>
int main() {
    int n,i;
    double price;      
    double max_price;
    printf("请输入商品数量n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("商品数量必须大于0！\n");
        return 0; 
    }
    printf("请依次输入 %d 件商品的价格:\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%lf", &price); 
        if (i == 1) {
            max_price = price;
        } 
        else if (price > max_price) {
            max_price = price;
        }
    }
    printf("最贵的商品价格为: %.2lf\n", max_price);

    return 0;
}
