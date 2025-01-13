// Определить, является ли треугольник со сторонами a, b и c равнобедренным
void task2(void) {
    double a, b, c;
    char t;
    printf("Введите длины сторон треугольника a, b и c: ");
    while (1) {
        if(scanf("%lf%lf%lf%c", &a, &b, &c, &t) == 4 && t=='\n' && a > 0 && b > 0 && c > 0){
            break;
        }
        else {
            printf("Некорректный ввод. Повторите еще раз: ");
            while (getchar() != '\n');
        }
    }
    
    if (a==b || b==c || a==c) {
        printf("Равнобедренный треугольник\n");
    }
    else{
        printf("Не равнобедренный треугольник\n");
    }
}