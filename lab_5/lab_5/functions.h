int start_1(char b);
int start_2(int numm);
int start_22(int numm);
int start_23(int column);
void print_arr(double * a, int n);
void print_arr2(int n, int *m, double ** a);
void print_arr3(int n, int *m, int ** a);


// Задание 1
void task1(void){
    char b = start_1(b);
    int n = start_2(n);
    double * a = malloc(n * sizeof(double));
    double a_1;
    
    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<n; k++){
            int r = (0 + rand()%2);
            if (r==1){
                a[k]= (-20 + rand()%100);
                fprintf(file, "%.2lf  ", a[k]);
            }
            else{
                a[k]= (-20.3 + rand()%100);
                fprintf(file, "%.2lf  ", a[k]);
            }
        }
        fclose(file);
    }
    else if(b == 'b'){
        FILE *file = fopen("array.txt", "w");
        int nms;
        for(int k=0;k<n;k++){
            while (1) {
                nms = scanf("%lf", &a_1);
                if (nms == 1) {
                    break;
                }
                else {
                    printf("Введен некорректный символ, введите еще раз: ");
                    while (getchar() != '\n');
                }
            }
            a[k] = a_1;
            fprintf(file, "%.2lf  ", a[k]);
        }
        fclose(file);
    }
    else if(b == 'c'){
        FILE *file = fopen("array.txt", "r");
        for(int k=0;k<n; k++){
            fscanf(file, "%lf", &a[k]);
        }
        fclose(file);
    }
    
    printf("Исходный массив: ");
    print_arr(a, n);
    for (int i = 0; i < n; i++) {
        if (a[i] == (int)a[i]) {
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
            i--;
        }
    }
    
    printf("Измененный массив: ");
    print_arr(a, n);
    free(a);
    
}

// Задание 2
void task2(void){
    char b = start_1(b);
    int n = start_22(n);
    int m = start_23(m);

    double **array = (double **)calloc(n, sizeof(double *));
    int *cols = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = (double *)calloc(m, sizeof(double));
        cols[i] = m;
    }

    if (b == 'a') {
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < m; j++) {
                int r = rand() % 2;
                if (r == 1) {
                    array[k][j] = -20 + rand() % 100;
                    fprintf(file, "%.2lf  ", array[k][j]);
                } else {
                    array[k][j] = -20.3 + rand() % 100;
                    fprintf(file, "%.2lf  ", array[k][j]);
                }
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if (b == 'b') {
        FILE *file = fopen("array.txt", "w");
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < m; j++) {
                while (scanf("%lf", &array[k][j]) != 1) {
                    printf("Введен некорректный символ, введите еще раз: ");
                    while (getchar() != '\n');
                }
                fprintf(file, "%.2lf  ", array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if (b == 'c') {
        FILE *file = fopen("array.txt", "r");
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < m; j++) {
                fscanf(file, "%lf", &array[k][j]);
            }
        }
        fclose(file);
    }

    printf("Исходный массив:\n");
    print_arr2(n, cols, array);

    for (int i = 0; i < n; i++) {
        int diagIndex = m - 1 - i;
        if (diagIndex >= 0 && diagIndex < m) {
            for (int j = diagIndex; j < cols[i] - 1; j++) {
                array[i][j] = array[i][j + 1];
            }
            cols[i]--;
            array[i] = (double *)realloc(array[i], cols[i] * sizeof(double));
        }
    }

    printf("\nИзмененный массив:\n");
    print_arr2(n, cols, array);

    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
    free(cols);


}
// Задание 3
void task3(void){
    char b = start_1(b);
    int n = start_22(n);
    int m = start_23(m);
    
    int ** array = (int**) calloc(n, sizeof(int*));
    int * cols = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = (int*) calloc(m, sizeof(int));
        cols[i] = m;
    }
    
    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<n; k++){
            for(int j=0;j<m; j++){
                array[k][j] = (-20 + rand()%100);
                fprintf(file, "%d  ", array[k][j]);
                array[k][m-1]=-100;
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if(b == 'b'){
        FILE *file = fopen("array.txt", "w");
        int nms;
        for(int k=0;k<n;k++){
            for(int j=0;j<m;j++){
                while (1) {
                    nms = scanf("%d", &array[k][j]);
                    if (nms == 1) {
                        break;
                    }
                    else {
                        printf("Введен некорректный символ, введите еще раз: ");
                        while (getchar() != '\n');
                    }
                }
                array[k][m-1]=-100;
                fprintf(file, "%d  ", array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if(b == 'c'){
        FILE *file = fopen("array.txt", "r");
        for(int k=0;k<n; k++){
            for(int j=0;j<m; j++){
                fscanf(file, "%d", &array[k][j]);
                array[k][m-1]=-100;
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    
    printf("Исходный массив: \n");
    print_arr3(n, cols, array);
    
    
    for(int i = 0; i < n; i++) {
        if((i+1)%2==0){
            for(int j = 0; j < cols[i]; j++){
                if(array[i][j]%2!=0){
                    cols[i]++;
                    array[i] = (int *)realloc(array[i], cols[i] * sizeof(int));
                    
                    for(int k=cols[i]-1; k > j; k--){
                        array[i][k] = array[i][k-1];
                    }
                    
                    array[i][j+1] = array[i][j];
                    j++;
                }
            }
        }
    }
    printf("\nИзмененный массив: \n");
    print_arr3(n, cols, array);
    
    for(int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
    free(cols);
    
}


// Основные функции
int isValidInput(const char *input){
    while (*input){
        if (!isdigit(*input)){
            return 0;
        }
        input++;
    }
    return 1;
}

int isValidInput_1(const char *input){
    while (*input){
        if (!isalpha(*input)){
            return 0;
        }
        input++;
    }
    return 1;
}

int start_1(char b){
    printf("Матрица заполняется случайными числами(a), вводимыми(b) или из файла(c): ");
    while (1) {
        char input[100];
//        scanf("%s", &input);
        // Указываем массив в который считывается строка, максимальное количество символов, поток из которого читаются данные
        fgets(input, sizeof(input), stdin);
        // Вместо символа новой строки, ставим символ конца строки
        input[strcspn(input, "\n")] = '\0';
        if (isValidInput_1(input) && (strcmp(input, "a") == 0 || strcmp(input, "b") == 0 || strcmp(input, "c") == 0)){
            sscanf(input, "%s", &b);
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
        }
    }
    return b;
}
int start_2(int numm){
    char input[100];
    printf("Введите количество элементов массива: ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (isValidInput(input) && atoi(input) > 0){
            sscanf(input, "%d", &numm);
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
        }
    }
    return numm;
}
int start_22(int numm){
    char input[100];
    printf("Введите количество строк матрицы: ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (isValidInput(input) && atoi(input) > 0){
            sscanf(input, "%d", &numm);
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
        }
    }
    return numm;
}
int start_23(int column){
    char input[100];
    printf("Введите количество столбцев матрицы: ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (isValidInput(input) && atoi(input) > 0){
            sscanf(input, "%d", &column);
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
        }
    }
    return column;
}
void print_arr(double * a, int n){
    for(int i = 0; i < n; i++)
        printf("%.1lf  ", a[i]);
    printf("\n");
}
void print_arr2(int n, int *m, double ** a){
    for(int i =0; i < n; i++){
        for(int j = 0; j < m[i]; j++){
            printf("%.1lf  ", a[i][j]);
        }
        printf("\n");
    }
}
void print_arr3(int n, int *m, int ** a){
    for(int i =0; i < n; i++){
        for(int j = 0; j < m[i]; j++){
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

int choice_task(int task){
    while (1) {
        char b;
        if(scanf("%d%c",&task, &b) == 2 && b=='\n'){
            break;
        }
        else {
            printf("Некорректный ввод. Повторите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return task;
}

void start(void){
    int task;
    printf("Выберите задание для проверки: ");
    
    task = choice_task(task);
    
    while (1) {
        if (task == 1){
            task1();
            break;;
        }
        if (task == 2){
            task2();
            break;
        }
        if (task == 3){
            task3();
            break;
        }
        else{
            printf("Неверный номер задания. Попробуйте еще раз: ");
            task = choice_task(task);
        }
    }
    
}