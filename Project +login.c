#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

float Electric_cost(float, int);
float Water_cost(float, int);
char pay_bill();
struct check_bill
{
    //data = billNo,Name,address,unit,datatype,billtype
    char *getdata[0][0];
    char *bill_data;
    char *billNo_data;
    char *billName_data;
    char *billAddress_data;
    char *billUnit_data;
    char *billDataType_data;
    char *billType_data;
};

main()
{
    struct check_bill ck_list[10];
    int fuction, selece_type = 0;
    int stop_loop = 1;
    float total, unit = 0;
    while (stop_loop)
    {
        printf("\n------------------------------------------------------------------\n");
        printf("Selece fuction \n");
        printf("1.Electric cost \n");
        printf("2.Water cost \n");
        printf("3.pay bill \n");
        printf("4.exit\n");
        printf("------------------------------------------------------------------\n");
        printf("\nEnter the function :");
        scanf("%d", &fuction);

        if (fuction == 1)
        {
            total = Electric_cost(unit, selece_type);

            printf("\nElectricity bill:%.2f baht\n", total);
        }
        else if (fuction == 2)
        {
            total = Water_cost(unit, selece_type);

            printf("Water bill:%.2f baht", total);
        }
        else if (fuction == 3)
        {
            pay_bill();
        }
        else if (fuction == 4)
        {
            stop_loop = 0;
        }
        else
        {
            printf("\nSelece fuctiont again\n\n");
        }
    }
    printf("\nEND");
}

char pay_bill()
{
    int stop_loop = 1;
    struct check_bill billNo_list[10];
    char billNo[11],
        //data = billNo,Name,address,unit,datatype,billtype
        //datatype 1.Electricity bill 2.Water bill
        //billtype if datatpe= 1 || 1.home 2.small business ...
        //billtype if datatpe= 2 || 1. Meter 1/2 inch 2.Meter 3/4 inch ...
        *data_bill[10][6] = {
            {"0425487548", "Mr.Smit GGEZ", "315 moo 7 Param2 Bangkok Thailand 10001", "150", "1", "1"},
            {"0252145663", "Mr.Smit GGEZ", "315 moo 7 Param2 Bangkok Thailand 10001", "150", "2", "1"},
            {"0372155687", "AUNAUN Hotel", "15 Nongyang KhamMuang Kalasin 46150", "7800", "1", "5"},
            {"0562145687", "AUNAUN Hotel", "15 Nongyang KhamMuang Kalasin 46150", "800", "2", "7"},
        };

    printf("Enter Bill NO :");
    scanf("%s", &billNo);
    int check, confrim = 0;
    int i, j = 0;
    while (stop_loop)
    {
        for (i = 0; i < 4; i++)
        {
            billNo_list[i].bill_data = data_bill[i][0];

            check = strcmp(billNo_list[i].bill_data, billNo);

            if (check == 0)
            {
                //เก็บ data ไว้ ใน struct แต่ละตัว
                billNo_list[0].billNo_data = data_bill[i][0];
                billNo_list[0].billName_data = data_bill[i][1];
                billNo_list[0].billAddress_data = data_bill[i][2];
                billNo_list[0].billUnit_data = data_bill[i][3];
                billNo_list[0].billDataType_data = data_bill[i][4];
                billNo_list[0].billType_data = data_bill[i][5];

                //test data in struct
                // printf("billNo: %s\n", billNo_list[0].billNo_data);
                // printf("billName: %s\n", billNo_list[0].billName_data);
                // printf("billAddress: %s\n", billNo_list[0].billAddress_data );
                // printf("Unit: %s\n", billNo_list[0].billUnit_data );
                // printf("DataType: %s\n", billNo_list[0].billDataType_data);
                // printf("billType :%s\n", billNo_list[0].billType_data );
                stop_loop = 0;
            }
            if (check != 0)
            {
                j++;
            }
        }

        if (j == 4)
        {
            printf("Bill No. error\n");
            confrim = 1;
            stop_loop = 0;
        }
    }

    if (confrim = 1)
    {
        //getdata from billNo_list[0]
        billNo_list->getdata[0][0] = billNo_list[0].billNo_data;
        billNo_list->getdata[0][1] = billNo_list[0].billName_data;
        billNo_list->getdata[0][2] = billNo_list[0].billAddress_data;
        billNo_list->getdata[0][3] = billNo_list[0].billUnit_data;
        billNo_list->getdata[0][4] = billNo_list[0].billDataType_data;
        billNo_list->getdata[0][5] = billNo_list[0].billType_data;

        printf("\n------------------------------------------------------------------\n");

        int ID[] = {0, 1, 2, 3, 4, 5};
        int *pionter = &ID[0];
        int billDataType = atoi(billNo_list->getdata[*(pionter)][*(pionter + 4)]);
        int selece_type = atoi(billNo_list->getdata[*(pionter)][*(pionter + 5)]);
        float unit = atof(billNo_list->getdata[*(pionter)][*(pionter + 3)]);
        float total;

        if (billDataType == 1)
        {
            printf("Type bill :Electricity bill\n");
        }
        else
        {
            printf("Type bill :Water_bill\n");
        }

        printf("bill No:%s\n", billNo_list->getdata[*(pionter)][*(pionter)]);

        if (billDataType == 1)
        {
            switch (selece_type)
            {
            case 1:
                printf("Home\n");
                break;
            case 2:
                printf("small business\n");

                break;
            case 3:
                printf("mid-sized business\n");
                break;
            case 4:
                printf("Big business\n");
                break;
            case 5:
                printf("Hotel and residential business\n");
                break;
            case 6:
                printf("Non-profit organization\n");
                break;
            case 7:
                printf("Water pumping business for Agriculture\n");
                break;
            case 8:
                printf("Temporary electricity\n");
                break;
            default:
                break;
            }
        }
        else
        {
            switch (selece_type)
            {
            case 1:
                printf("Meter 1/2 inch\n");
                break;
            case 2:
                printf("Meter 3/4 inch\n");

                break;
            case 3:
                printf("Meter 1 inch\n");
                break;
            case 4:
                printf("Meter 1 1/2 inch\n");
                break;
            case 5:
                printf("Meter 2 inch\n");
                break;
            case 6:
                printf("Meter 3 inch\n");
                break;
            case 7:
                printf("Meter 4 inch\n");
                break;
            case 8:
                printf("Meter 6 inch\n");
                break;
            case 9:
                printf("Meter 8 inch\n");
                break;
            case 10:
                printf("Meter 12 inch\n");
                break;
            case 11:
                printf("11. Meter 16 inch\n");
                break;

            default:
                break;
            }
        }

        printf("Name :%s\n", billNo_list->getdata[*(pionter)][*(pionter + 1)]);
        printf("Address :%s\n", billNo_list->getdata[*(pionter)][*(pionter + 2)]);

        printf("Unit use :%.0f unit\n", unit);

        if (billDataType == 1)
        {
            total = Electric_cost(unit, selece_type);
            printf("Electricity bill :%.2f bath", total);
        }
        else
        {
            total = Electric_cost(unit, selece_type);
            printf("Water bill :%.2f bath", total);
        }
    }
    printf("\n------------------------------------------------------------------\n");
}
float Water_cost(float unit, int selece_type)
{
    int selece, check_bill_type, stop_loop = 1;
    float water_bill, unit_W = unit;
    if (unit_W > 0)
    {
        check_bill_type = 1;
    }
    else
    {
        printf("Eneter water_bill unit:");
        scanf("%f", &unit);
    }

    while (stop_loop)
    {
        if (check_bill_type == 1)
        {
            selece = selece_type;
        }
        else
        {
            printf("\n------------------------------------------------------------------\n");
            printf("Select Water meter\n");
            printf("1. Meter 1/2 inch\n");
            printf("2. Meter 3/4 inch\n");
            printf("3. Meter 1 inch\n");
            printf("4. Meter 1 1/2 inch\n");
            printf("5. Meter 2 inch\n");
            printf("6. Meter 3 inch\n");
            printf("7. Meter 4 inch\n");
            printf("8. Meter 6 inch\n");
            printf("9. Meter 8 inch\n");
            printf("10. Meter 12 inch\n");
            printf("11. Meter 16 inch\n");
            printf("------------------------------------------------------------------\n");
            printf("Selece type : ");
            scanf("%d", &selece);
        }

        if (selece == 1)
        {
            if (unit >= 0 && unit <= 10)
            {
                water_bill = ((unit * 10) + 25 + 7.0) / 100;
            }
            else if (unit >= 11 && unit <= 20)
            {
                water_bill = ((unit * 10) + 25 + 7.0) / 100;
            }
            else if (unit >= 21 && unit <= 30)
            {
                water_bill = ((unit * 10) + 25 + 7.0) / 100;
            }
            else if (unit >= 31 && unit <= 50)
            {
                water_bill = ((unit * 20) + 25 + 7.0) / 100;
            }
            else if (unit >= 51 && unit <= 80)
            {
                water_bill = ((unit * 30) + 25 + 7.0) / 100;
            }
            else if (unit >= 81 && unit <= 100)
            {
                water_bill = ((unit * 20) + 25 + 7.0) / 100;
            }
            else if (unit >= 101 && unit <= 300)
            {
                water_bill = ((unit * 200) + 25 + 7.0) / 100;
            }
            else if (unit >= 301 && unit <= 1000)
            {
                water_bill = ((unit * 700) + 25 + 7.0) / 100;
            }
            else if (unit >= 1001)
            {
                water_bill = ((unit * 1000) + 25 + 7.0) / 100;
            }

            stop_loop = 0;
        }
        else if (selece == 2)
        {
            if (unit >= 0 && unit <= 10)
            {
                water_bill = ((unit * 10) + 40 + 7.0) / 100;
            }
            else if (unit >= 11 && unit <= 20)
            {
                water_bill = ((unit * 10) + 40 + 7.0) / 100;
            }
            else if (unit >= 21 && unit <= 30)
            {
                water_bill = ((unit * 10) + 40 + 7.0) / 100;
            }
            else if (unit >= 31 && unit <= 50)
            {
                water_bill = ((unit * 20) + 40 + 7.0) / 100;
            }
            else if (unit >= 51 && unit <= 80)
            {
                water_bill = ((unit * 30) + 40 + 7.0) / 100;
            }
            else if (unit >= 81 && unit <= 100)
            {
                water_bill = ((unit * 20) + 40 + 7.0) / 100;
            }
            else if (unit >= 101 && unit <= 300)
            {
                water_bill = ((unit * 200) + 40 + 7.0) / 100;
            }
            else if (unit >= 301 && unit <= 1000)
            {
                water_bill = ((unit * 700) + 40 + 7.0) / 100;
            }
            else if (unit >= 1001 && unit <= 2000)
            {
                water_bill = ((unit * 1000) + 40 + 7.0) / 100;
            }
            else if (unit >= 2001)
            {
                water_bill = ((unit * 1000) + 40 + 7.0) / 100;
            }
            stop_loop = 0;
        }
        else if (selece == 3)
        {
            if (unit >= 0 && unit <= 10)
            {
                water_bill = ((unit * 10) + 50 + 7.0 / 100);
            }
            else if (unit >= 11 && unit <= 20)
            {
                water_bill = ((unit * 10) + 50 + 7.0 / 100);
            }
            else if (unit >= 21 && unit <= 30)
            {
                water_bill = ((unit * 10) + 50 + 7.0 / 100); //Meter 1
            }
            else if (unit >= 31 && unit <= 50)
            {
                water_bill = ((unit * 20) + 50 + 7.0) / 100;
            }
            else if (unit >= 51 && unit <= 80)
            {
                water_bill = ((unit * 30) + 50 + 7.0) / 100;
            }
            else if (unit >= 81 && unit <= 100)
            {
                water_bill = ((unit * 20) + 50 + 7.0) / 100;
            }
            else if (unit >= 101 && unit <= 300)
            {
                water_bill = ((unit * 200) + 50 + 7.0) / 100;
            }
            else if (unit >= 301 && unit <= 1000)
            {
                water_bill = ((unit * 700) + 50 + 7.0) / 100;
            }
            else if (unit >= 1001)
            {
                water_bill = ((unit * 1000) + 50 + 7.0) / 100;
            }
            stop_loop = 0;
        }
        else if (selece == 4)
        {
            if (unit >= 0 && unit <= 10)
            {
                water_bill = ((unit * 10) + 80 + 7.0) / 100;
            }
            else if (unit >= 11 && unit <= 20)
            {
                water_bill = ((unit * 10) + 80 + 7.0) / 100;
            }
            else if (unit >= 21 && unit <= 30)
            {
                water_bill = ((unit * 10) + 80 + 7.0) / 100; //Meter 1 1/2
            }
            else if (unit >= 31 && unit <= 50)
            {
                water_bill = ((unit * 20) + 80 + 7.0) / 100;
            }
            else if (unit >= 51 && unit <= 80)
            {
                water_bill = ((unit * 30) + 80 + 7.0) / 100;
            }
            else if (unit >= 81 && unit <= 100)
            {
                water_bill = ((unit * 20) + 80 + 7.0) / 100;
            }
            else if (unit >= 101 && unit <= 300)
            {
                water_bill = ((unit * 200) + 80 + 7.0) / 100;
            }
            else if (unit >= 301 && unit <= 1000)
            {
                water_bill = ((unit * 700) + 80 + 7.0) / 100;
            }
            else if (unit >= 1001)
            {
                water_bill = ((unit * 1000) + 80 + 7.0) / 100;
            }
            stop_loop = 0;
        }
        else if (selece == 5)
        {
            if (unit >= 0 && unit <= 10)
            {
                water_bill = ((unit * 10) + 300 + 7.0) / 100;
            }
            else if (unit >= 11 && unit <= 20)
            {
                water_bill = ((unit * 10) + 300 + 7.0) / 100;
            }
            else if (unit >= 21 && unit <= 30)
            {
                water_bill = ((unit * 10) + 300 + 7.0) / 100; //Meter 1 1/2
            }
            else if (unit >= 31 && unit <= 50)
            {
                water_bill = ((unit * 20) + 300 + 7.0) / 100;
            }
            else if (unit >= 51 && unit <= 80)
            {
                water_bill = ((unit * 30) + 300 + 7.0) / 100;
            }
            else if (unit >= 81 && unit <= 100)
            {
                water_bill = ((unit * 20) + 300 + 7.0) / 100;
            }
            else if (unit >= 101 && unit <= 300)
            {
                water_bill = ((unit * 200) + 300 + 7.0) / 100;
            }
            else if (unit >= 301 && unit <= 1000)
            {
                water_bill = ((unit * 700) + 300 + 7.0) / 100;
            }
            else if (unit >= 1001)
            {
                water_bill = ((unit * 1000) + 300 + 7.0) / 100;
            }
            stop_loop = 0;
        }
        else if (selece == 6)
        {
            if (unit >= 0 && unit <= 10)
            {
                water_bill = ((unit * 10) + 400 + 7.0) / 100;
            }
            else if (unit >= 11 && unit <= 20)
            {
                water_bill = ((unit * 10) + 400 + 7.0) / 100;
            }
            else if (unit >= 21 && unit <= 30)
            {
                water_bill = ((unit * 10) + 400 + 7.0) / 100; //Meter 1 1/2
            }
            else if (unit >= 31 && unit <= 50)
            {
                water_bill = ((unit * 20) + 400 + 7.0) / 100;
            }
            else if (unit >= 51 && unit <= 80)
            {
                water_bill = ((unit * 30) + 400 + 7.0) / 100;
            }
            else if (unit >= 81 && unit <= 100)
            {
                water_bill = ((unit * 20) + 400 + 7.0) / 100;
            }
            else if (unit >= 101 && unit <= 300)
            {
                water_bill = ((unit * 200) + 400 + 7.0) / 100;
            }
            else if (unit >= 301 && unit <= 1000)
            {
                water_bill = ((unit * 700) + 400 + 7.0) / 100;
            }
            else if (unit >= 1001)
            {
                water_bill = ((unit * 1000) + 400 + 7.0) / 100;
            }
            stop_loop = 0;
        }
        else if (selece == 7)
        {
            if (unit >= 0 && unit <= 10)
            {
                water_bill = ((unit * 10) + 500 + 7.0) / 100;
            }
            else if (unit >= 11 && unit <= 20)
            {
                water_bill = ((unit * 10) + 500 + 7.0) / 100;
            }
            else if (unit >= 21 && unit <= 30)
            {
                water_bill = ((unit * 10) + 500 + 7.0) / 100; //Meter 1 1/2
            }
            else if (unit >= 31 && unit <= 50)
            {
                water_bill = ((unit * 20) + 500 + 7.0) / 100;
            }
            else if (unit >= 51 && unit <= 80)
            {
                water_bill = ((unit * 30) + 500 + 7.0) / 100;
            }
            else if (unit >= 81 && unit <= 100)
            {
                water_bill = ((unit * 20) + 500 + 7.0) / 100;
            }
            else if (unit >= 101 && unit <= 500)
            {
                water_bill = ((unit * 200) + 500 + 7.0) / 100;
            }
            else if (unit >= 301 && unit <= 1000)
            {
                water_bill = ((unit * 700) + 500 + 7.0) / 100;
            }
            else if (unit >= 1001)
            {
                water_bill = ((unit * 1000) + 500 + 7.0) / 100;
            }
            stop_loop = 0;
        }
        else if (selece == 8)
        {
            if (unit >= 0 && unit <= 10)
            {
                water_bill = ((unit * 10) + 900 + 7.0) / 100;
            }
            else if (unit >= 11 && unit <= 20)
            {
                water_bill = ((unit * 10) + 900 + 7.0) / 100;
            }
            else if (unit >= 21 && unit <= 30)
            {
                water_bill = ((unit * 10) + 900 + 7.0) / 100; //Meter 1 1/2
            }
            else if (unit >= 31 && unit <= 50)
            {
                water_bill = ((unit * 20) + 900 + 7.0) / 100;
            }
            else if (unit >= 51 && unit <= 80)
            {
                water_bill = ((unit * 30) + 900 + 7.0) / 100;
            }
            else if (unit >= 81 && unit <= 100)
            {
                water_bill = ((unit * 20) + 900 + 7.0) / 100;
            }
            else if (unit >= 101 && unit <= 500)
            {
                water_bill = ((unit * 200) + 900 + 7.0) / 100;
            }
            else if (unit >= 301 && unit <= 1000)
            {
                water_bill = ((unit * 700) + 900 + 7.0) / 100;
            }
            else if (unit >= 1001)
            {
                water_bill = ((unit * 1000) + 900 + 7.0) / 100;
            }
            stop_loop = 0;
        }
        else if (selece == 9)
        {
            if (unit >= 0 && unit <= 10)
            {
                water_bill = ((unit * 10) + 1100 + 7.0) / 100;
            }
            else if (unit >= 11 && unit <= 20)
            {
                water_bill = ((unit * 10) + 1100 + 7.0) / 100;
            }
            else if (unit >= 21 && unit <= 30)
            {
                water_bill = ((unit * 10) + 1100 + 7.0) / 100; //Meter 1 1/2
            }
            else if (unit >= 31 && unit <= 50)
            {
                water_bill = ((unit * 20) + 1100 + 7.0) / 100;
            }
            else if (unit >= 51 && unit <= 80)
            {
                water_bill = ((unit * 30) + 1100 + 7.0) / 100;
            }
            else if (unit >= 81 && unit <= 100)
            {
                water_bill = ((unit * 20) + 1100 + 7.0) / 100;
            }
            else if (unit >= 101 && unit <= 500)
            {
                water_bill = ((unit * 200) + 1100 + 7.0) / 100;
            }
            else if (unit >= 301 && unit <= 1000)
            {
                water_bill = ((unit * 700) + 1100 + 7.0) / 100;
            }
            else if (unit >= 1001)
            {
                water_bill = ((unit * 1000) + 1100 + 7.0) / 100;
            }
            stop_loop = 0;
        }
        else if (selece == 10)
        {
            if (unit >= 0 && unit <= 10)
            {
                water_bill = ((unit * 10) + 3500 + 7.0) / 100;
            }
            else if (unit >= 11 && unit <= 20)
            {
                water_bill = ((unit * 10) + 3500 + 7.0) / 100;
            }
            else if (unit >= 21 && unit <= 30)
            {
                water_bill = ((unit * 10) + 3500 + 7.0) / 100; //Meter 1 1/2
            }
            else if (unit >= 31 && unit <= 50)
            {
                water_bill = ((unit * 20) + 3500 + 7.0) / 100;
            }
            else if (unit >= 51 && unit <= 80)
            {
                water_bill = ((unit * 30) + 3500 + 7.0) / 100;
            }
            else if (unit >= 81 && unit <= 100)
            {
                water_bill = ((unit * 20) + 3500 + 7.0) / 100;
            }
            else if (unit >= 101 && unit <= 500)
            {
                water_bill = ((unit * 200) + 3500 + 7.0) / 100;
            }
            else if (unit >= 301 && unit <= 1000)
            {
                water_bill = ((unit * 700) + 3500 + 7.0) / 100;
            }
            else if (unit >= 1001)
            {
                water_bill = ((unit * 1000) + 3500 + 7.0) / 100;
            }
            stop_loop = 0;
        }
        else if (selece == 11)
        {
            if (unit >= 0 && unit <= 10)
            {
                water_bill = ((unit * 10) + 5000 + 7.0) / 100;
            }
            else if (unit >= 11 && unit <= 20)
            {
                water_bill = ((unit * 10) + 5000 + 7.0) / 100;
            }
            else if (unit >= 21 && unit <= 30)
            {
                water_bill = ((unit * 10) + 5000 + 7.0) / 100; //Meter 1 1/2
            }
            else if (unit >= 31 && unit <= 50)
            {
                water_bill = ((unit * 20) + 5000 + 7.0) / 100;
            }
            else if (unit >= 51 && unit <= 80)
            {
                water_bill = ((unit * 30) + 5000 + 7.0) / 100;
            }
            else if (unit >= 81 && unit <= 100)
            {
                water_bill = ((unit * 20) + 5000 + 7.0) / 100;
            }
            else if (unit >= 101 && unit <= 500)
            {
                water_bill = ((unit * 200) + 5000 + 7.0) / 100;
            }
            else if (unit >= 301 && unit <= 1000)
            {
                water_bill = ((unit * 700) + 5000 + 7.0) / 100;
            }
            else if (unit >= 1001)
            {
                water_bill = ((unit * 1000) + 3500 + 7.0) / 100;
            }
            stop_loop = 0;
        }
        else
        {
            printf("\nSelece fuctiont again\n\n");
        }
    }

    return water_bill;
}

float Electric_cost(float unit, int selece_type)
{
    int selece, fuction, stop_loop = 1, check_bill_type = 0;
    float electricity_bill, unit_E = unit;

    if (unit_E > 0)
    {
        check_bill_type = 1;
    }
    else
    {
        printf("Enter electricity unit :");
        scanf("%f", &unit);
    }

    while (stop_loop)
    {
        if (check_bill_type == 1)
        {
            selece = selece_type;
        }
        else
        {
            printf("\n------------------------------------------------------------------\n");
            printf("1.Home \n");
            printf("2.small business \n");
            printf("3.mid-sized business \n");
            printf("4.Big business \n");
            printf("5.Hotel and residential business\n");
            printf("6.Non-profit organization \n");
            printf("7.Water pumping business for Agriculture \n");
            printf("8.Temporary electricity \n");
            printf("------------------------------------------------------------------\n");
            printf("Selece type : ");
            scanf("%d", &selece);
        }

        if (selece == 1)
        {
            if (unit >= 1 && unit <= 5)
            {
                electricity_bill = unit * 8.19;
            }
            else if (unit >= 6 && unit <= 15)
            {
                electricity_bill = (unit * 1.3576) + 8.19;
            }
            else if (unit >= 16 && unit <= 25)
            {
                electricity_bill = (unit * 1.5445) + 8.19;
            }
            else if (unit >= 26 && unit <= 35)
            {
                electricity_bill = (unit * 1.7968) + 8.19;
            }
            else if (unit >= 36 && unit <= 100)
            {
                electricity_bill = (unit * 2.1800) + 8.19;
            }
            else if (unit >= 101 && unit <= 150)
            {
                electricity_bill = (unit * 2.2734) + 8.19;
            }
            else if (unit >= 151 && unit <= 400)
            {
                electricity_bill = (unit * 2.7781) + 8.19;
            }
            else
            {
                electricity_bill = (unit * 2.9780) + 8.19;
            }
            stop_loop = 0;
        }

        else if (selece == 2)
        {
            if (unit >= 1 && unit <= 150)
            {
                electricity_bill = (unit * 3.2484) + 46.16;
            }
            else if (unit >= 151 && unit <= 400)
            {
                electricity_bill = (unit * 4.2218) + 46.16;
            }
            else
            {
                electricity_bill = (unit * 4.4217) + 46.16;
            }
            stop_loop = 0;
        }
        else if (selece == 3)
        {
            if (unit >= 1 && unit <= 12)
            {
                electricity_bill = (unit * 3.1751) + 312.24;
            }
            else if (unit >= 13 && unit <= 24)
            {
                electricity_bill = (unit * 3.1471) + 312.24;
            }
            else
            {
                electricity_bill = (unit * 3.1097) + 312.24;
            }
            stop_loop = 0;
        }
        else if (selece == 4)
        {

            while (stop_loop)
            {
                printf("\n1.On Peak MON-FRI 09.00-22.00 \n");
                printf("2.Off Peak MON-FRI 22.00-09.00 \n");
                printf("Enter On or Off : ");
                scanf("%d", &fuction);
                if (fuction == 1)
                {
                    if (unit >= 1 && unit <= 12)
                    {
                        electricity_bill = (unit * 4.3297) + 312.24;
                    }
                    else if (unit >= 13 && unit <= 24)
                    {
                        electricity_bill = (unit * 4.1839) + 312.24;
                    }
                    else
                    {
                        electricity_bill = (unit * 4.1025) + 312.24;
                    }
                    stop_loop = 0;
                }
                else if (fuction == 2)
                {
                    if (unit >= 1 && unit <= 12)
                    {
                        electricity_bill = (unit * 2.6369) + 312.24;
                    }
                    else if (unit >= 13 && unit <= 24)
                    {
                        electricity_bill = (unit * 2.6037) + 312.24;
                    }
                    else
                    {
                        electricity_bill = (unit * 2.5849) + 312.24;
                    }
                    stop_loop = 0;
                }
            }
        }
        else if (selece == 5)
        {
            if (unit >= 1 && unit <= 12)
            {
                electricity_bill = (unit * 3.1751) + 312.24;
            }
            else if (unit >= 13 && unit <= 24)
            {
                electricity_bill = (unit * 3.1471) + 312.24;
            }
            else
            {
                electricity_bill = (unit * 3.1097) + 312.24;
            }
            stop_loop = 0;
        }
        else if (selece == 6)
        {
            if (unit >= 1 && unit <= 10)
            {
                electricity_bill = (unit * 2.8013) + 20;
            }
            else if (unit >= 11 && unit <= 12)
            {
                electricity_bill = (unit * 3.8919) + 20;
            }
            else if (unit >= 13 && unit <= 24)
            {
                electricity_bill = (unit * 3.5849) + 312.24;
            }
            else
            {
                electricity_bill = (unit * 3.4149) + 312.24;
            }
            stop_loop = 0;
        }
        else if (selece == 7)
        {
            if (unit >= 1 && unit <= 100)
            {
                electricity_bill = (unit * 2.0889) + 115.16;
            }
            else
            {
                electricity_bill = (unit * 3.2405) + 115.16;
            }
            stop_loop = 0;
        }
        else if (selece == 8)
        {
            if (unit >= 1 && unit <= 9999990)
            {
                electricity_bill = (unit * 6.8025);
            }
            stop_loop = 0;
        }
        else
        {
            printf("\nSelece fuctiont again\n\n");
        }
    }

    return electricity_bill;
}
