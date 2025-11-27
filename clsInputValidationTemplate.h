
#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
using namespace std;
template <class    temp>
class    clsInputValidationTemplate
{

	template <typename  T>
	static bool IsNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate  Date, clsDate  From, clsDate  To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
		{
			return true;
		}

		return false;
	}

	template <typename  T>
	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	template <typename  T>
	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Number = ReadIntNumber<T>();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber<T>();
		}
		return Number;
	}

	static bool IsValidate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

	int main()
	{

		cout << clsInputValidationTemplate::IsNumberBetween<int>(5, 1, 10) << endl;
		cout << clsInputValidationTemplate::IsNumberBetween<float>(5.2, 1.8, 10.3) << endl;
		cout << clsInputValidationTemplate::IsNumberBetween<short>(5, 1, 10) << endl;
		cout << clsInputValidationTemplate::IsNumberBetween<bool>(5, 1, 10) << endl;
		cout << clsInputValidationTemplate::IsDateBetween(clsDate(), clsDate(8, 8, 2025), clsDate(2, 10, 2023)) << endl;
		cout << clsInputValidationTemplate::ReadNumber<int>();
		cout << clsInputValidationTemplate::ReadNumber<float>();
		cout << clsInputValidationTemplate::ReadNumber<short>();
		cout << clsInputValidationTemplate::ReadNumberBetween<float>(20.5, 55.3);
		cout << clsInputValidationTemplate::ReadNumberBetween<int>(20, 55);
		cout << clsInputValidationTemplate::ReadNumberBetween<short>(20.5, 55.3);
		cout << clsInputValidationTemplate::ReadString() << endl;
		cout << clsInputValidationTemplate::IsValidate(clsDate(25, 11, 2025)) << endl;
	}
};




