#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string outputs[6] = {"1: Print help",
                         "2: Print exchange status",
                         "3: Place an ask",
                         "4: Place a bid",
                         "5: Print wallet",
                         "6: Continuation"};

    string helps[6] = {
        "1: Print help - This option will display a guide to all the available operations and commands in the system.",
        "2: Print exchange status - Use this option to see the current exchange rates for various currencies to Bitcoin.",
        "3: Place an ask - This option allows you to place an ask order to buy Bitcoin with the selected currency.",
        "4: Place a bid - Use this option to place a bid to sell Bitcoin. You can specify the amount and confirm the transaction.",
        "5: Print wallet - This will display your current wallet balance in Bitcoin.",
        "6: Continue - Use this option to choose whether you would like to continue using the program or exit."};

    string currencies[] = {"USD", "EUR", "GBP", "JPY", "AUD"};
    double exchangeRates[] = {91689.17, 86969.01, 72548.05, 14173908.02, 141842.05};

    int userInput;
    double ask, bid, afterConvert = 0, wallet = 0;
    bool continueation = true;

    while (continueation)
    {
        for (string option : outputs)
        {
            cout << option << endl;
        }
        cout << "Type the number: ";

        cin >> userInput;
        cout << "" << endl;
        switch (userInput)
        {
        case 1:
        {
            for (string h : helps)
            {
                cout << h << endl;
            }
            cout << "" << endl;
            break;
        }
        case 2:
        {
            for (int i = 0; i < (sizeof(currencies) / sizeof(currencies[0])); i++)
            {
                cout << currencies[i] << " : " << exchangeRates[i] << endl;
            }
            cout << "" << endl;
            break;
        }
        case 3:
        {
            double amount, bits, oneBitcoin, bitcoinAmount;
            string currencyType = "";
            bool convertToBitcoins = false;
            string accepttation;

            for (string c : currencies)
            {
                cout << c << endl;
            }
            cout << "Please type the currency: ";
            cin >> currencyType;
            cout << "\n";

            cout << "Please type how much you would like pay: ";
            cin >> amount;
            cout << "\n";

            transform(currencyType.begin(), currencyType.end(), currencyType.begin(), ::toupper);

            for (int i = 0; i < (sizeof(currencies) / sizeof(currencies[0])); i++)
            {
                if (currencyType == currencies[i])
                {
                    oneBitcoin = exchangeRates[i];
                    bitcoinAmount = amount / exchangeRates[i];
                    break;
                }
            }

            cout << "You can buy " << bitcoinAmount << " bitcoins for your amount" << endl;
            cout << "Would you like to convert: yes/no" << endl;
            cin >> accepttation;
            transform(accepttation.begin(), accepttation.end(), accepttation.begin(), ::tolower);
            convertToBitcoins = accepttation == "yes" ? true : false;
            wallet = convertToBitcoins == true ? wallet + bitcoinAmount : wallet;
            if (accepttation == "yes")
                cout << "Your current amount in the wallet is " << wallet << endl;
            else if (accepttation == "no")
                break;
            currencyType = "";
            cout << "" << endl;
            break;
        }
        case 4:
        {
            double bitAmount;
            string confirmation;
            cout << "Your wallet: " << wallet << endl;
            cout << "Enter how much you would plan to Bid: ";
            cin >> bitAmount;
            cout << "\n";
            cout << "Enter bit amount is " << bitAmount << "! Would like to confirm? yes/no ";
            cin >> confirmation;
            cout << "\n";
            transform(confirmation.begin(), confirmation.end(), confirmation.begin(), ::tolower);
            if (confirmation == "yes" && (wallet < 0 || bitAmount > wallet))
            {
                cerr << "Sorry! you cannot bid now due to low saffician balance" << endl;
            }
            else
            {
                wallet = (confirmation == "yes" && wallet > 0) ? wallet - bitAmount : wallet;
                cout << "\n";
                cout << "We have deducted " << bitAmount << " from your wallet, now you have " << wallet << " in your wallet." << endl;
            }
            cout << "" << endl;
            break;
        }
        case 5:
        {
            cout << "You have " << wallet << " in your wallet." << endl;
            cout << "" << endl;
            break;
        }
        case 6:
        {
            string userContinuation;
            cout << "Would you like to continue? Yes / No -> ";
            cin >> userContinuation;
            cout << "\n";
            transform(userContinuation.begin(), userContinuation.end(), userContinuation.begin(), ::tolower);
            continueation = userContinuation == "yes" ? true : false;
            cout << "" << endl;
            break;
        }
        default:
            cout << "Invalid option. Please choose a valid option." << endl;
            cout << "" << endl;
            break;
        }
    }

    return 0;
}