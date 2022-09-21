#define _BUFFER_LEN 1024
#define _FIRST_NAME_MAX_LEN 32
#define _LAST_NAME_MAX_LEN 32
#define _STREET_NAME_MAX_LEN 64
#define _APT_NUM_MAX_LEN 8
#define _CITY_NAME_MAX_LEN 64
#define _STATE_MAX_LEN 2
#define _PHONE_TYPE_MAX_LEN 8
#define _RECORD_MAX_LEN 4
#define _ICD_CODE_MAX_LEN 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

enum State {
    NONE_STATE, AK, AL, AR, AZ, CA, CO, CT, DC, DE, FL, GA, HI, IA, ID, IL,
    IN, KS, KY, LA, MA, MD, ME, MI, MN, MO, MS, MT, NC, ND, NE, NH, NJ, NM, NV,
    NY, OH, OK, OR, PA, RI, SC, SD, TN, TX, UT, VA, VT, WA, WI, WV, WY
};
enum Phone {
    NONE_PHONE, HOME, CELL, WORK
};

typedef struct _PHONE_INFO {
    unsigned short areaCode;
    unsigned int phoneNum;
    enum Phone phoneEnum;
} PHONE_INFO;

typedef struct _ICD_INFO {
    size_t icdCodeLen;
    unsigned int date;
    char* icdCode;
} ICD_INFO;

typedef struct _CMD_LINE_PARAM {
    char* workingDir;
    size_t workingDirLen;
    unsigned int numRecords;
} CMD_LINE_PARAM;

/* Function prints an apartment number if there is one */
void printAptNum(char* aptNum) {
    if (aptNum[0] != '\0') {
        printf("Apt# %s\n", aptNum);
    }
    else {
        printf("\n");
    }
}

/* Function takes a date converted into an unsigned int, deconstructs the date and prints it */
void printDate(ICD_INFO icdCodeList[], int i) {
    unsigned int Date = icdCodeList[i].date;
    unsigned int Year = 0;
    unsigned int Month = 0;
    unsigned int Day = 0;

    Year = Date / 10000;
    Date %= 10000;
    Month = Date / 100;
    Day = Date % 100;

    printf("ICD Code entry date: %u/%u/%u", Month, Day, Year);
}

/* Function takes a stateEnum and prints the postal code for that state */
void printState(enum State stateEnum) {
    switch (stateEnum) {
    case NONE_STATE:
        printf("**ERROR** NO STATE ENTERED **ERROR**");
        break;
    case AK:
        printf("AK");
        break;
    case AL:
        printf("AL");
        break;
    case AR:
        printf("AR");
        break;
    case AZ:
        printf("AZ");
        break;
    case CA:
        printf("CA");
        break;
    case CO:
        printf("CO");
        break;
    case CT:
        printf("CT");
        break;
    case DC:
        printf("DC");
        break;
    case DE:
        printf("DE");
        break;
    case FL:
        printf("FL");
        break;
    case GA:
        printf("GA");
        break;
    case HI:
        printf("HI");
        break;
    case IA:
        printf("IA");
        break;
    case ID:
        printf("ID");
        break;
    case IL:
        printf("IL");
        break;
    case IN:
        printf("IN");
        break;
    case KS:
        printf("KS");
        break;
    case KY:
        printf("KY");
        break;
    case LA:
        printf("LA");
        break;
    case MA:
        printf("MA");
        break;
    case MD:
        printf("MD");
        break;
    case ME:
        printf("ME");
        break;
    case MI:
        printf("MI");
        break;
    case MN:
        printf("MN");
        break;
    case MO:
        printf("MO");
        break;
    case MS:
        printf("MS");
        break;
    case MT:
        printf("MT");
        break;
    case NC:
        printf("NC");
        break;
    case ND:
        printf("ND");
        break;
    case NE:
        printf("NE");
        break;
    case NH:
        printf("NH");
        break;
    case NJ:
        printf("NJ");
        break;
    case NM:
        printf("NM");
        break;
    case NV:
        printf("NV");
        break;
    case NY:
        printf("NY");
        break;
    case OH:
        printf("OH");
        break;
    case OK:
        printf("OK");
        break;
    case OR:
        printf("OR");
        break;
    case PA:
        printf("PA");
        break;
    case RI:
        printf("RI");
        break;
    case SC:
        printf("SC");
        break;
    case SD:
        printf("SD");
        break;
    case TN:
        printf("TN");
        break;
    case TX:
        printf("TX");
        break;
    case UT:
        printf("UT");
        break;
    case VA:
        printf("VA");
        break;
    case VT:
        printf("VT");
        break;
    case WA:
        printf("WA");
        break;
    case WI:
        printf("WI");
        break;
    case WV:
        printf("WV");
        break;
    case WY:
        printf("WY");
    };
}

void printPhone(enum Phone phoneEnum) {
    switch (phoneEnum) {
    case NONE_PHONE:
        printf("**ERROR** NO PHONE TYPE ENTERED **ERROR**");
        break;
    case HOME:
        printf("HOME");
        break;
    case CELL:
        printf("CELL");
        break;
    case WORK:
        printf("WORK");
    };
}

/* Function takes a numerical year, month, and day and coverts it into an unsigned int for storage */
unsigned int convertDateToInt(unsigned int Year, unsigned int Month, unsigned int Day) {
    unsigned int date = 0;
    return date = (Year * 10000) + (Month * 100) + Day;
}

/* Function takes a 2 char array and determines if the array is a valid
   state postal code. If it is not a valid state postal code, NONE_STATE
   will be returned */
enum State isValidState(char* state) {
    enum State stateEnum = NONE_STATE;
    switch (state[0]) {
    case 'A':
        switch (state[1]) {
        case 'K':
            stateEnum = AK;
            break;
        case 'L':
            stateEnum = AL;
            break;
        case 'R':
            stateEnum = AR;
            break;
        case 'Z':
            stateEnum = AZ;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'C':
        switch (state[1]) {
        case 'A':
            stateEnum = CA;
            break;
        case 'O':
            stateEnum = CO;
            break;
        case 'T':
            stateEnum = CT;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'D':
        switch (state[1]) {
        case 'C':
            stateEnum = DC;
            break;
        case 'E':
            stateEnum = DE;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'F':
        switch (state[1]) {
        case 'L':
            stateEnum = FL;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'G':
        switch (state[1]) {
        case 'A':
            stateEnum = GA;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'H':
        switch (state[1]) {
        case 'I':
            stateEnum = HI;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'I':
        switch (state[1]) {
        case 'A':
            stateEnum = IA;
            break;
        case 'D':
            stateEnum = ID;
            break;
        case 'L':
            stateEnum = IL;
            break;
        case 'N':
            stateEnum = IN;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'K':
        switch (state[1]) {
        case 'S':
            stateEnum = KS;
            break;
        case 'Y':
            stateEnum = KY;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'L':
        switch (state[1]) {
        case 'A':
            stateEnum = LA;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'M':
        switch (state[1]) {
        case 'A':
            stateEnum = MA;
            break;
        case 'D':
            stateEnum = MD;
            break;
        case 'E':
            stateEnum = ME;
            break;
        case 'I':
            stateEnum = MI;
            break;
        case 'N':
            stateEnum = MN;
            break;
        case 'O':
            stateEnum = MO;
            break;
        case 'S':
            stateEnum = MS;
            break;
        case 'T':
            stateEnum = MT;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'N':
        switch (state[1]) {
        case 'C':
            stateEnum = NC;
            break;
        case 'D':
            stateEnum = ND;
            break;
        case 'E':
            stateEnum = NE;
            break;
        case 'H':
            stateEnum = NH;
            break;
        case 'J':
            stateEnum = NJ;
            break;
        case 'M':
            stateEnum = NM;
            break;
        case 'V':
            stateEnum = NV;
            break;
        case 'Y':
            stateEnum = NY;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'O':
        switch (state[1]) {
        case 'H':
            stateEnum = OH;
            break;
        case 'K':
            stateEnum = OK;
            break;
        case 'R':
            stateEnum = OR;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'P':
        switch (state[1]) {
        case 'A':
            stateEnum = PA;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'R':
        switch (state[1]) {
        case 'I':
            stateEnum = RI;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'S':
        switch (state[1]) {
        case 'C':
            stateEnum = SC;
            break;
        case 'D':
            stateEnum = SD;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'T':
        switch (state[1]) {
        case 'N':
            stateEnum = TN;
            break;
        case 'X':
            stateEnum = TX;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'U':
        switch (state[1]) {
        case 'T':
            stateEnum = UT;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'V':
        switch (state[1]) {
        case 'A':
            stateEnum = VA;
            break;
        case 'T':
            stateEnum = VT;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;

    case 'W':
        switch (state[1]) {
        case 'A':
            stateEnum = WA;
            break;
        case 'I':
            stateEnum = WI;
            break;
        case 'V':
            stateEnum = WV;
            break;
        case 'Y':
            stateEnum = WY;
            break;
        default:
            stateEnum = NONE_STATE;
        };
        break;
    };
    return stateEnum;
}

/* Function takes a 4 char array and determines if the array is a valid
   phone type between HOME, CELL, and WORK. If it is not a valid phone
   type according to the first char only, NONE_PHONE is returned */
enum Phone isValidPhone(char* phoneType) {
    enum Phone phoneEnum = NONE_PHONE;
    switch (phoneType[0]) {
    case 'C':
    case 'c':
        phoneEnum = CELL;
        break;
    case 'H':
    case 'h':
        phoneEnum = HOME;
        break;
    case 'W':
    case 'w':
        phoneEnum = WORK;
        break;
    default:
        phoneEnum = NONE_PHONE;
    };
    return phoneEnum;
}

bool isValidDate(unsigned int year, unsigned int month, unsigned int day) {
    bool validDate = false;
    unsigned int Year = year;
    unsigned int Month = month;
    unsigned int Day = day;
    if ((Year != 0) && (Month == 2)) {
        if (Year % 400 == 0) {
            if ((Day <= 29) && (Day > 0)) {
                validDate = true;
            }
            else {
                validDate = false;
            }
        }
        else if (Year % 100 == 0) {
            if ((Day <= 28) && (Day > 0)) {
                validDate = true;
            }
            else {
                validDate = false;
            }
        }
        else if (Year % 4 == 0) {
            if ((Day <= 29) && (Day > 0)) {
                validDate = true;
            }
            else {
                validDate = false;
            }
        }
        else {
            if ((Day <= 28) && (Day > 0)) {
                validDate = true;
            }
            else {
                validDate = false;
            }
        }
    }
    else if ((Year != 0) && ((Month == 4) || (Month == 6) || (Month == 9) || (Month == 11))) {
        if ((Day <= 30) && (Day > 0)) {
            validDate = true;
        }
        else {
            validDate = false;
        }
    }
    else if ((Year != 0) && ((Month <= 12) && (Month != 2) && (Month != 0))) {
        if ((Day <= 31) && (Day > 0)) {
            validDate = true;
        }
        else {
            validDate = false;
        }
    }
    else {
        validDate = false;
    }
    if (validDate == false) {
        printf("**ERROR** DATE IS NOT A VALID DATE **ERROR**\n");
    }
    Year = 0;
    Month = 0;
    Day = 0;
    return validDate;
}

void intToASCII(unsigned int idxNum, char* charBuffer) {
    size_t i = strlen(charBuffer);
    unsigned int mod = 1000000000;
    while (idxNum > 0) {
        unsigned int digit = idxNum / mod;
        idxNum %= mod;
        mod /= 10;
        digit += 48;
        charBuffer[i] = (char)digit;
        ++i;
    }
}

void getFileName(char* lastName, char* firstName, char* charBuffer, unsigned int idxNum) {
    strcpy(charBuffer, lastName);
    strcat(charBuffer, "_");
    strcat(charBuffer, firstName);
    strcat(charBuffer, "_");
    intToASCII(idxNum, charBuffer);
    strcat(charBuffer, ".icd");
}

int main(int argc, char* argv[]) {

    char* firstName = NULL;
    char* lastName = NULL;
    char* streetName = NULL;
    char* aptNum = NULL;
    char* cityName = NULL;
    char* state = NULL;
    char* phoneType = NULL;
    char charBuffer[_BUFFER_LEN];
    unsigned short zipPlusFour = 10000;
    unsigned short streetNum = 0;
    unsigned int zipCode = 0;
    unsigned int Year = 0;
    unsigned int Month = 0;
    unsigned int Day = 0;
    unsigned long numBuffer = 0;
    unsigned int idxNum = 0;
    enum State stateEnum = NONE_STATE;
    ICD_INFO* icdCodeList = NULL;

    bool validFirstName = false;
    bool validLastName = false;
    bool validStreetNum = false;
    bool validStreetName = false;
    bool validApt = false;
    bool validCity = false;
    bool validState = false;
    bool validZip = false;
    bool validPhone = false;
    bool validPlusFour = false;
    bool validAreaCode = false;
    bool validPhoneNum = false;
    bool validDate = false;
    bool validSave = false;
    bool validRead = false;
    bool validIdxNum = false;
    bool validCmd = false;

    FILE* fptr = NULL;
    fptr = fopen("ICD.idx", "r");
    while (fptr == NULL) {
        fptr = fopen("ICD.idx", "w");
    }
    memset(charBuffer, 0, _BUFFER_LEN);
    fgets(charBuffer, _BUFFER_LEN, fptr);
    sscanf(charBuffer, "%u", &idxNum);
    fclose(fptr);

    PHONE_INFO phoneInfo = {
        .areaCode = 0,
        .phoneNum = 0,
        .phoneEnum = NONE_PHONE
    };

    ICD_INFO icdInfo = {
        .icdCodeLen = 0,
        .date = 0,
        .icdCode = NULL
    };

    CMD_LINE_PARAM userParameters = {
        .workingDir = NULL,
        .workingDirLen = 0,
        .numRecords = _RECORD_MAX_LEN
    };

    do {
        if (argc == 1) {
            validCmd = true;
        }
        else if ((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "-r") == 0)) {
            printf("Commands -c and -r are exclusive and cannot be used together.\n");
            return 1;
        }
        else if ((strcmp(argv[1], "-r") == 0) && (strcmp(argv[2], "-c") == 0)) {
            printf("Commands -c and -r are exclusive and cannot be used together.\n");
            return 1;
        }
        else if (argc > 1 && argc <= 3) {
            switch (argv[1][0]) {
            case '-':
                switch (argv[1][1]) {
                case 'c':
                    userParameters.numRecords = atoi(argv[2]);
                    validCmd = true;
                    break;
                case 'r':
                    fptr = fopen(argv[2], "r");
                    if (fptr == NULL) {
                        printf("**ERROR** FILE NAME: '%s' NOT FOUND **ERROR **\n", argv[2]);
                        return 1;
                    }
                    else {
                        fgets(charBuffer, _BUFFER_LEN, fptr);
                        charBuffer[strcspn(charBuffer, "\n")] = '\0';
                        firstName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                        strcpy(firstName, charBuffer);
                        memset(charBuffer, 0, _BUFFER_LEN);

                        fgets(charBuffer, _BUFFER_LEN, fptr);
                        charBuffer[strcspn(charBuffer, "\n")] = '\0';
                        lastName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                        strcpy(lastName, charBuffer);
                        memset(charBuffer, 0, _BUFFER_LEN);

                        fscanf(fptr, "%hu\n", &streetNum);

                        fgets(charBuffer, _BUFFER_LEN, fptr);
                        charBuffer[strcspn(charBuffer, "\n")] = '\0';
                        streetName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                        strcpy(streetName, charBuffer);
                        memset(charBuffer, 0, _BUFFER_LEN);

                        fgets(charBuffer, _BUFFER_LEN, fptr);
                        charBuffer[strcspn(charBuffer, "\n")] = '\0';
                        aptNum = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                        strcpy(aptNum, charBuffer);
                        memset(charBuffer, 0, _BUFFER_LEN);

                        fgets(charBuffer, _BUFFER_LEN, fptr);
                        charBuffer[strcspn(charBuffer, "\n")] = '\0';
                        cityName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                        strcpy(cityName, charBuffer);
                        memset(charBuffer, 0, _BUFFER_LEN);

                        fscanf(fptr, "%d\n", &stateEnum);
                        fscanf(fptr, "%u\n%hu\n", &zipCode, &zipPlusFour);
                        fscanf(fptr, "%hu\n%u\n%d\n", &phoneInfo.areaCode, &phoneInfo.phoneNum, &phoneInfo.phoneEnum);
                        fscanf(fptr, "%u\n", &userParameters.numRecords);

                        icdCodeList = (ICD_INFO*)malloc(userParameters.numRecords * sizeof(ICD_INFO));
                        unsigned int i = 0;
                        while (i < userParameters.numRecords) {
                            fscanf(fptr, "%zu\n%u\n", &icdCodeList[i].icdCodeLen, &icdCodeList[i].date);

                            fgets(charBuffer, _BUFFER_LEN, fptr);
                            charBuffer[strcspn(charBuffer, "\n")] = '\0';
                            icdCodeList[i].icdCode = (char*)malloc((icdCodeList[i].icdCodeLen + 1) * sizeof(char));
                            strcpy(icdCodeList[i].icdCode, charBuffer);
                            memset(charBuffer, 0, _BUFFER_LEN);

                            ++i;
                        }
                        fclose(fptr);
                        printf("\n\nPatient information:\n\n%s %s\n", firstName, lastName);
                        printf("%hu %s ", streetNum, streetName);
                        printAptNum(aptNum);
                        printf("%s, ", cityName);
                        printState(stateEnum);
                        printf(" %u-%04hu\n", zipCode, zipPlusFour);
                        printf("Phone type: ");
                        printPhone(phoneInfo.phoneEnum);
                        printf("\nPhone number: %hu-%u\n\n", phoneInfo.areaCode, phoneInfo.phoneNum);
                        fscanf(fptr, "%u\n", &userParameters.numRecords);

                        i = 0;
                        while (i < userParameters.numRecords) {
                            printf("ICD Code %d: %s\n", (i + 1), icdCodeList[i].icdCode);
                            printDate(icdCodeList, i);
                            printf("\n\n");
                            ++i;
                        }
                        free(firstName);
                        free(lastName);
                        free(streetName);
                        free(aptNum);
                        free(cityName);
                        i = 0;
                        while (i < userParameters.numRecords) {
                            free(icdCodeList[i].icdCode);
                            ++i;
                        }
                        free(icdCodeList);
                        return 0;
                    }
                case 'p':
                    patientNum = atoi(argv[2]);
                    while (patientNum > 0) {
                        printf("Input the number of patient records to be entered for patient number %i: ", patientNum);
                        scanf("%i", &userParameters.numRecords);
                        /*code for inputing and saving patient records here*/

                    }
                    return 0;
                case 'h':
                    printf("List of valid command line parameters:\n");
                    printf("-c {count}: Used to set the number of ICD Codes to value other than default.\n");
                    printf("-r {file_name.icd}: Used to open an existing patient file.\n");
                    printf("-h: Help menu.\n");
                    printf("Commands -c and -r are exclusive and cannot be used together.\n");
                    return 0;
                };
                break;
            default:
                printf("Not a valid command line parameter.\n");
                printf("List of valid command line parameters:\n");
                printf("-c {count}: Used to set the number of ICD Codes to value other than default.\n");
                printf("-r {file_name.icd}: Used to open an existing patient file.\n");
                printf("-h: Help menu.\n");
                printf("Commands -c and -r are exclusive and cannot be used together.\n");
                return 1;
            };
        }
        else if (argc > 3) {
            printf("Too many command line arguements used, valid parameters are:\n");
            printf("-c {count}: Used to set the number of ICD Codes to value other than default.\n");
            printf("-r {file_name.icd}: Used to open an existing patient file.\n");
            printf("-h: Help menu.\n");
            printf("Commands -c and -r are exclusive and cannot be used together.\n");
            return 1;
        }
    } while (validCmd == false);

    printf("Welcome to the MedEX EMR & Patient Management System.\n\n");

    if (argc == 1) {
        do {
            printf("Do you want to open an existing record? Y/N:");
            fgets(charBuffer, _BUFFER_LEN, stdin);
            charBuffer[strcspn(charBuffer, "\n")] = '\0';
            if (strlen(charBuffer) == 0) {
                printf("**ERROR** INPUT CANNOT BE BLANK **ERROR**\n");
                validRead = false;
            }
            else if (charBuffer[0] == 'y' || charBuffer[0] == 'Y') {
                do {
                    printf("Please enter the Patient's first name: ");
                    fgets(charBuffer, _BUFFER_LEN, stdin);
                    charBuffer[strcspn(charBuffer, "\n")] = '\0';
                    if (strlen(charBuffer) > _FIRST_NAME_MAX_LEN) {
                        printf("**ERROR** FIRST NAME EXCEEDS MAX LENGTH **ERROR**\n");
                        memset(charBuffer, 0, _BUFFER_LEN);
                        validFirstName = false;
                    }
                    else if (strlen(charBuffer) == 0) {
                        printf("**ERROR** FIRST NAME CANNOT BE BLANK **ERROR**\n");
                        memset(charBuffer, 0, _BUFFER_LEN);
                        validFirstName = false;
                    }
                    else if (strlen(charBuffer) <= _FIRST_NAME_MAX_LEN) {
                        validFirstName = true;
                    }
                    else {
                        memset(charBuffer, 0, _BUFFER_LEN);
                        validFirstName = false;
                    }
                } while (validFirstName == false);

                firstName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                strcpy(firstName, charBuffer);
                memset(charBuffer, 0, _BUFFER_LEN);

                do {
                    printf("Please enter the Patient's last name: ");
                    fgets(charBuffer, _BUFFER_LEN, stdin);
                    charBuffer[strcspn(charBuffer, "\n")] = '\0';
                    if (strlen(charBuffer) > _LAST_NAME_MAX_LEN) {
                        printf("**ERROR** LAST NAME EXCEEDS MAX LENGTH **ERROR**\n");
                        memset(charBuffer, 0, _BUFFER_LEN);
                        validLastName = false;
                    }
                    else if (strlen(charBuffer) == 0) {
                        printf("**ERROR** LAST NAME CANNOT BE BLANK **ERROR**\n");
                        memset(charBuffer, 0, _BUFFER_LEN);
                        validLastName = false;
                    }
                    else if (strlen(charBuffer) <= _LAST_NAME_MAX_LEN) {
                        validLastName = true;
                    }
                    else {
                        memset(charBuffer, 0, _BUFFER_LEN);
                        validLastName = false;
                    }
                } while (validLastName == false);

                lastName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                strcpy(lastName, charBuffer);
                memset(charBuffer, 0, _BUFFER_LEN);

                /*do {
                    printf("Please enter the patient's record number: ");
                    scanf("%lu", &numBuffer);
                    if ((numBuffer <= 1000000000) && (numBuffer != 0)) {
                        idxNum = (unsigned int)numBuffer;
                        validIdxNum = true;
                    }
                    else {
                        printf("**ERROR** RECORD NUMBER IS OUT OF RANGE **ERROR**\n");
                        validIdxNum = false;
                    }
                    while (getchar() != '\n');
                } while (validIdxNum == false);*/
                printf("Please enter the patient's record number: ");
                scanf("%u", &idxNum);
                numBuffer = 0;
                /*getFileName(lastName, firstName, charBuffer, idxNum);*/
                sprintf(charBuffer, "%s_%s_%u.icd", lastName, firstName, idxNum);
                fptr = fopen(charBuffer, "r");
                if (fptr == NULL) {
                    printf("**ERROR** FILE NAME: '%s' NOT FOUND **ERROR **\n", charBuffer);
                    validRead = false;
                }
                else {
                    fgets(charBuffer, _BUFFER_LEN, fptr);
                    charBuffer[strcspn(charBuffer, "\n")] = '\0';
                    firstName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                    strcpy(firstName, charBuffer);
                    memset(charBuffer, 0, _BUFFER_LEN);

                    fgets(charBuffer, _BUFFER_LEN, fptr);
                    charBuffer[strcspn(charBuffer, "\n")] = '\0';
                    lastName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                    strcpy(lastName, charBuffer);
                    memset(charBuffer, 0, _BUFFER_LEN);

                    fscanf(fptr, "%hu\n", &streetNum);

                    fgets(charBuffer, _BUFFER_LEN, fptr);
                    charBuffer[strcspn(charBuffer, "\n")] = '\0';
                    streetName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                    strcpy(streetName, charBuffer);
                    memset(charBuffer, 0, _BUFFER_LEN);

                    fgets(charBuffer, _BUFFER_LEN, fptr);
                    charBuffer[strcspn(charBuffer, "\n")] = '\0';
                    aptNum = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                    strcpy(aptNum, charBuffer);
                    memset(charBuffer, 0, _BUFFER_LEN);

                    fgets(charBuffer, _BUFFER_LEN, fptr);
                    charBuffer[strcspn(charBuffer, "\n")] = '\0';
                    cityName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
                    strcpy(cityName, charBuffer);
                    memset(charBuffer, 0, _BUFFER_LEN);

                    fscanf(fptr, "%d\n", &stateEnum);
                    fscanf(fptr, "%u\n%hu\n", &zipCode, &zipPlusFour);
                    fscanf(fptr, "%hu\n%u\n%d\n", &phoneInfo.areaCode, &phoneInfo.phoneNum, &phoneInfo.phoneEnum);
                    fscanf(fptr, "%u\n", &userParameters.numRecords);

                    icdCodeList = (ICD_INFO*)malloc(userParameters.numRecords * sizeof(ICD_INFO));
                    unsigned int i = 0;
                    while (i < userParameters.numRecords) {
                        fscanf(fptr, "%zu\n%u\n", &icdCodeList[i].icdCodeLen, &icdCodeList[i].date);

                        fgets(charBuffer, _BUFFER_LEN, fptr);
                        charBuffer[strcspn(charBuffer, "\n")] = '\0';
                        icdCodeList[i].icdCode = (char*)malloc((icdCodeList[i].icdCodeLen + 1) * sizeof(char));
                        strcpy(icdCodeList[i].icdCode, charBuffer);
                        memset(charBuffer, 0, _BUFFER_LEN);

                        ++i;
                    }
                    fclose(fptr);
                    printf("\n\nPatient information:\n\n%s %s\n", firstName, lastName);
                    printf("%hu %s ", streetNum, streetName);
                    printAptNum(aptNum);
                    printf("%s, ", cityName);
                    printState(stateEnum);
                    printf(" %u-%04hu\n", zipCode, zipPlusFour);
                    printf("Phone type: ");
                    printPhone(phoneInfo.phoneEnum);
                    printf("\nPhone number: %hu-%u\n\n", phoneInfo.areaCode, phoneInfo.phoneNum);

                    i = 0;
                    while (i < userParameters.numRecords) {
                        printf("ICD Code %d: %s\n", (i + 1), icdCodeList[i].icdCode);
                        printDate(icdCodeList, i);
                        printf("\n\n");
                        ++i;
                    }
                    free(firstName);
                    free(lastName);
                    free(streetName);
                    free(aptNum);
                    free(cityName);
                    i = 0;
                    while (i < userParameters.numRecords) {
                        free(icdCodeList[i].icdCode);
                        ++i;
                    }
                    free(icdCodeList);
                    return 0;
                }
            }
            else if (charBuffer[0] == 'n' || charBuffer[0] == 'N') {
                validRead = true;
            }
            else {
                printf("**ERROR** INPUT WAS NOT A VALID INPUT TYPE Y/N **ERROR**\n");
                validRead = false;
            }
        } while (validRead == false);
    }

    do {
        printf("Please enter the Patient's first name: ");
        /* Takes user input into a large input buffer, then copies the input string
        and inputs into the correct string */
        fgets(charBuffer, _BUFFER_LEN, stdin);
        charBuffer[strcspn(charBuffer, "\n")] = '\0';
        if (strlen(charBuffer) > _FIRST_NAME_MAX_LEN) {
            printf("**ERROR** FIRST NAME EXCEEDS MAX LENGTH **ERROR**\n");
            memset(charBuffer, 0, _BUFFER_LEN);
            validFirstName = false;
        }
        else if (strlen(charBuffer) == 0) {
            printf("**ERROR** FIRST NAME CANNOT BE BLANK **ERROR**\n");
            memset(charBuffer, 0, _BUFFER_LEN);
            validFirstName = false;
        }
        else if (strlen(charBuffer) <= _FIRST_NAME_MAX_LEN) {
            validFirstName = true;
        }
        else {
            memset(charBuffer, 0, _BUFFER_LEN);
            validFirstName = false;
        }
    } while (validFirstName == false);

    firstName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
    strcpy(firstName, charBuffer);
    memset(charBuffer, 0, _BUFFER_LEN);

    do {
        printf("Please enter the Patient's last name: ");
        fgets(charBuffer, _BUFFER_LEN, stdin);
        charBuffer[strcspn(charBuffer, "\n")] = '\0';
        if (strlen(charBuffer) > _LAST_NAME_MAX_LEN) {
            printf("**ERROR** LAST NAME EXCEEDS MAX LENGTH **ERROR**\n");
            memset(charBuffer, 0, _BUFFER_LEN);
            validLastName = false;
        }
        else if (strlen(charBuffer) == 0) {
            printf("**ERROR** LAST NAME CANNOT BE BLANK **ERROR**\n");
            memset(charBuffer, 0, _BUFFER_LEN);
            validLastName = false;
        }
        else if (strlen(charBuffer) <= _LAST_NAME_MAX_LEN) {
            validLastName = true;
        }
        else {
            memset(charBuffer, 0, _BUFFER_LEN);
            validLastName = false;
        }
    } while (validLastName == false);

    lastName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
    strcpy(lastName, charBuffer);
    memset(charBuffer, 0, _BUFFER_LEN);

    do {
        printf("Input the street/house number: ");
        scanf("%lu", &numBuffer);
        if ((numBuffer <= 65535) && (numBuffer != 0)) {
            streetNum = (unsigned short)numBuffer;
            validStreetNum = true;
        }
        else {
            printf("**ERROR** STREET/HOUSE NUMBER IS OUT OF RANGE **ERROR**\n");
            validStreetNum = false;
        }
        /* Flush the input stream to remove any \n to prevent skipping future inputs */
        while (getchar() != '\n');

    } while (validStreetNum == false);

    numBuffer = 0;

    do {
        printf("Input the street name: ");
        fgets(charBuffer, _BUFFER_LEN, stdin);
        charBuffer[strcspn(charBuffer, "\n")] = '\0';
        if (strlen(charBuffer) > _STREET_NAME_MAX_LEN) {
            printf("**ERROR** STREET NAME EXCEEDS MAX LENGTH **ERROR**\n");
            memset(charBuffer, 0, _BUFFER_LEN);
            validStreetName = false;
        }
        else if (strlen(charBuffer) == 0) {
            printf("**ERROR** STREET NAME CANNOT BE BLANK **ERROR**\n");
            memset(charBuffer, 0, _BUFFER_LEN);
            validStreetName = false;
        }
        else if (strlen(charBuffer) <= _STREET_NAME_MAX_LEN) {
            validStreetName = true;
        }
        else {
            memset(charBuffer, 0, _BUFFER_LEN);
            validStreetName = false;
        }
    } while (validStreetName == false);

    streetName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
    strcpy(streetName, charBuffer);
    memset(charBuffer, 0, _BUFFER_LEN);

    do {
        printf("Input the apartment number if applicable, otherwise, press ENTER: ");
        fgets(charBuffer, _APT_NUM_MAX_LEN, stdin);
        charBuffer[strcspn(charBuffer, "\n")] = '\0';
        if (strlen(charBuffer) > _APT_NUM_MAX_LEN) {
            printf("**ERROR** STREET NAME EXCEEDS MAX LENGTH **ERROR**\n");
            memset(charBuffer, 0, _BUFFER_LEN);
            validApt = false;
        }
        else if (strlen(charBuffer) <= _APT_NUM_MAX_LEN && charBuffer[0] != '\0') {
            aptNum = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
            strcpy(aptNum, charBuffer);
            memset(charBuffer, 0, _BUFFER_LEN);
            validApt = true;
        }
        else {
            aptNum = (char*)malloc(sizeof(char));
            aptNum[0] = '\0';
            memset(charBuffer, 0, _BUFFER_LEN);
            validApt = true;
        }
    } while (validApt == false);

    do {
        printf("Input city name: ");
        fgets(charBuffer, _BUFFER_LEN, stdin);
        charBuffer[strcspn(charBuffer, "\n")] = '\0';
        if (strlen(charBuffer) > _CITY_NAME_MAX_LEN) {
            printf("**ERROR** CITY NAME EXCEEDS MAX LENGTH **ERROR**\n");
            memset(charBuffer, 0, _BUFFER_LEN);
            validCity = false;
        }
        else if (strlen(charBuffer) == 0) {
            printf("**ERROR** CITY NAME CANNOT BE BLANK **ERROR**\n");
            memset(charBuffer, 0, _BUFFER_LEN);
            validCity = false;
        }
        else if (strlen(charBuffer) <= _CITY_NAME_MAX_LEN) {
            validCity = true;
        }
        else {
            memset(charBuffer, 0, _BUFFER_LEN);
            validCity = false;
        }
    } while (validCity == false);

    cityName = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
    strcpy(cityName, charBuffer);
    memset(charBuffer, 0, _BUFFER_LEN);

    do {
        do {
            printf("Input the state postal abbreviation: ");
            fgets(charBuffer, _BUFFER_LEN, stdin);
            charBuffer[strcspn(charBuffer, "\n")] = '\0';
            if (strlen(charBuffer) > _STATE_MAX_LEN) {
                printf("**ERROR** POSTAL ABBREVIATION EXCEEDS MAX LENGTH **ERROR**\n");
                memset(charBuffer, 0, _BUFFER_LEN);
                validState = false;
            }
            else if (strlen(charBuffer) == 0) {
                printf("**ERROR** POSTAL ABBREVIATION CANNOT BE BLANK **ERROR**\n");
                memset(charBuffer, 0, _BUFFER_LEN);
                validState = false;
            }
            else if (strlen(charBuffer) <= _STATE_MAX_LEN) {
                validState = true;
            }
            else {
                memset(charBuffer, 0, _BUFFER_LEN);
                validState = false;
            }
        } while (validState == false);

        state = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
        strcpy(state, charBuffer);
        memset(charBuffer, 0, _BUFFER_LEN);

        int i = 0;
        while (state[i] != '\0') {
            state[i] = toupper(state[i]);
            ++i;
        }
        stateEnum = isValidState(state);
        free(state);
    } while (stateEnum == NONE_STATE);

    do {
        printf("Input the zip code: ");
        scanf("%lu", &numBuffer);
        if ((numBuffer >= 1000) && (numBuffer <= 99950)) {
            zipCode = (unsigned int)numBuffer;
            validZip = true;
        }
        else {
            printf("**ERROR** ZIP CODE IS OUT OF RANGE **ERROR**\n");
            validZip = false;
        }
        while (getchar() != '\n');

    } while (validZip == false);

    numBuffer = 0;

    do {
        printf("Input the +4, enter 0 if not known: ");
        scanf("%lu", &numBuffer);
        if (numBuffer <= 9999) {
            zipPlusFour = (unsigned short)numBuffer;
            validPlusFour = true;
        }
        else {
            printf("**ERROR** +4 IS OUT OF RANGE **ERROR**\n");
            validPlusFour = false;
        }
        while (getchar() != '\n');

    } while (validPlusFour == false);

    numBuffer = 0;

    do {
        printf("Input the phone type; HOME / CELL / WORK: ");
        fgets(charBuffer, _BUFFER_LEN, stdin);
        charBuffer[strcspn(charBuffer, "\n")] = '\0';
        if (strlen(charBuffer) > _PHONE_TYPE_MAX_LEN) {
            printf("**ERROR** PHONE TYPE EXCEEDS MAX LENGTH **ERROR**\n");
            memset(charBuffer, 0, _BUFFER_LEN);
            validPhone = false;
        }
        else if (strlen(charBuffer) == 0) {
            printf("**ERROR** PHONE TYPE CANNOT BE BLANK **ERROR**\n");
            memset(charBuffer, 0, _BUFFER_LEN);
            validPhone = false;
        }
        else if (strlen(charBuffer) <= _PHONE_TYPE_MAX_LEN) {
            validPhone = true;
        }
        else {
            memset(charBuffer, 0, _BUFFER_LEN);
            validPhone = false;
        }
    } while (validPhone == false);

    phoneType = (char*)malloc((strlen(charBuffer) + 1) * sizeof(char));
    strcpy(phoneType, charBuffer);
    memset(charBuffer, 0, _BUFFER_LEN);

    phoneInfo.phoneEnum = isValidPhone(phoneType);
    free(phoneType);

    do {
        printf("Input the the area code: ");
        scanf("%lu", &numBuffer);
        if ((numBuffer >= 200) && (numBuffer <= 999)) {
            phoneInfo.areaCode = (unsigned short)numBuffer;
            validAreaCode = true;
        }
        else {
            printf("**ERROR** AREA CODE IS OUT OF RANGE **ERROR**\n");
            validAreaCode = false;
        }
        while (getchar() != '\n');

    } while (validAreaCode == false);

    numBuffer = 0;

    do {
        printf("Input the the phone number, no spaces or hyphens: ");
        scanf("%lu", &numBuffer);
        if ((numBuffer >= 2010000) && (numBuffer <= 9999999)) {
            phoneInfo.phoneNum = (unsigned int)numBuffer;
            validPhoneNum = true;
        }
        else {
            printf("**ERROR** PHONE NUMBER IS OUT OF RANGE **ERROR**\n");
            validPhoneNum = false;
        }
        while (getchar() != '\n');

    } while (validPhoneNum == false);

    numBuffer = 0;

    icdCodeList = (ICD_INFO*)malloc(userParameters.numRecords * sizeof(ICD_INFO));
    unsigned int i = 0;
    for (i; i < userParameters.numRecords; ++i) {
        printf("Input ICD code #%d for the patient: ", (i + 1));
        fgets(charBuffer, _BUFFER_LEN, stdin);
        charBuffer[strcspn(charBuffer, "\n")] = '\0';
        if (strlen(charBuffer) <= _ICD_CODE_MAX_LEN && strlen(charBuffer) != 0)
        {
            icdCodeList[i].icdCodeLen = strlen(charBuffer);
            icdCodeList[i].icdCode = (char*)malloc((icdCodeList[i].icdCodeLen + 1) * sizeof(char));
            strcpy(icdCodeList[i].icdCode, charBuffer);
            do {
                do {
                    printf("Input year in the format YYYY: ");
                    scanf("%lu", &numBuffer);
                    if (numBuffer > 1920 && numBuffer < 2030) {
                        Year = (unsigned int)numBuffer;
                        validDate = true;
                    }
                    else {
                        printf("**ERROR** YEAR IS OUT OF RANGE **ERROR**\n");
                        validDate = false;
                        break;
                    }
                    while (getchar() != '\n');

                    printf("Input month in the format MM: ");
                    scanf("%lu", &numBuffer);
                    if (numBuffer <= 12 && numBuffer != 0) {
                        Month = (unsigned int)numBuffer;
                        validDate = true;
                    }
                    else {
                        printf("**ERROR** MONTH IS OUT OF RANGE **ERROR**\n");
                        validDate = false;
                        break;
                    }
                    while (getchar() != '\n');

                    printf("Input day in the format DD: ");
                    scanf("%lu", &numBuffer);
                    if (numBuffer <= 31 && numBuffer != 0) {
                        Day = (unsigned int)numBuffer;
                        validDate = true;
                    }
                    else {
                        printf("**ERROR** DAY IS OUT OF RANGE **ERROR**\n");
                        validDate = false;
                        break;
                    }
                    while (getchar() != '\n');
                } while (validDate == false);
            } while (isValidDate(Year, Month, Day) == false);
            icdCodeList[i].date = convertDateToInt(Year, Month, Day);
        }
        else if (strlen(charBuffer) > _ICD_CODE_MAX_LEN) {
            printf("**ERROR** ICD CODE OUT OF RANGE **ERROR**\n");
            --i;
        }
        else if (strlen(charBuffer) == 0) {
            printf("**ERROR** ICD CODE CANNOT BE BLANK **ERROR**\n");
        }
    }

    printf("\n\nPatient information:\n\n%s %s\n", firstName, lastName);
    printf("%hu %s ", streetNum, streetName);
    printAptNum(aptNum);
    printf("%s, ", cityName);
    printState(stateEnum);
    printf(" %u-%04hu\n", zipCode, zipPlusFour);
    printf("Phone type: ");
    printPhone(phoneInfo.phoneEnum);
    printf("\nPhone number: %hu-%u\n\n", phoneInfo.areaCode, phoneInfo.phoneNum);

    i = 0;
    while (i < userParameters.numRecords)
    {
        printf("ICD Code %d: %s\n", (i + 1), icdCodeList[i].icdCode);
        printDate(icdCodeList, i);
        printf("\n\n");
        ++i;
    }

    do {
        printf("Would you like to save the Patient information? Y/N: ");
        fgets(charBuffer, _BUFFER_LEN, stdin);
        charBuffer[strcspn(charBuffer, "\n")] = '\0';
        if (strlen(charBuffer) == 0) {
            printf("**ERROR** INPUT CANNOT BE BLANK **ERROR**\n");
            validSave = false;
        }
        else if (charBuffer[0] == 'y' || charBuffer[0] == 'Y') {
            fptr = fopen("ICD.idx", "r");
            memset(charBuffer, 0, _BUFFER_LEN);
            idxNum += 1;
            /*getFileName(lastName, firstName, charBuffer, idxNum);*/
            sprintf(charBuffer, "%s_%s_%u.icd", lastName, firstName, idxNum);
            fptr = fopen(charBuffer, "w");
            fprintf(fptr, "%s\n%s\n", firstName, lastName);
            fprintf(fptr, "%hu\n%s\n%s\n", streetNum, streetName, aptNum);
            fprintf(fptr, "%s\n%d\n", cityName, stateEnum);
            fprintf(fptr, "%u\n%hu\n", zipCode, zipPlusFour);
            fprintf(fptr, "%hu\n%u\n%d\n", phoneInfo.areaCode, phoneInfo.phoneNum, phoneInfo.phoneEnum);
            fprintf(fptr, "%u\n", userParameters.numRecords);
            i = 0;
            while (i < userParameters.numRecords) {
                fprintf(fptr, "%zu\n%u\n%s\n", icdCodeList[i].icdCodeLen, icdCodeList[i].date, icdCodeList[i].icdCode);
                ++i;
            }
            fclose(fptr);
            memset(charBuffer, 0, _BUFFER_LEN);
            fptr = fopen("ICD.idx", "w");
            sprintf(charBuffer, "%u", idxNum);
            fwrite(charBuffer, sizeof(char), strlen(charBuffer), fptr);
            fclose(fptr);
            validSave = true;
        }
        else if (charBuffer[0] == 'n' || charBuffer[0] == 'N') {
            validSave = true;
        }
        else {
            printf("**ERROR** INPUT WAS NOT A VALID INPUT TYPE Y/N **ERROR**\n");
            validSave = false;
        }
    } while (validSave == false);

    free(firstName);
    free(lastName);
    free(streetName);
    free(aptNum);
    free(cityName);
    i = 0;
    while (i < userParameters.numRecords) {
        free(icdCodeList[i].icdCode);
        ++i;
    }
    free(icdCodeList);
    return 0;
}