#include "pch.h"
#include "CppUnitTest.h"
#include "UnitTest1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(B01)
	{
	public:
		struct Truck truck {};
		struct Package pk {};
		TEST_METHOD(BB01A)
		{
			
			truck.capacityHolding = 30;
			truck.weightHolding = 1000;
			
			pk.capacity = 1;
			pk.weight = 100;

			int check = isValidWeight(truck, pk);
			Assert::AreEqual(1,check);
		}

		TEST_METHOD(BB01B)
		{

			truck.capacityHolding = 47;
			truck.weightHolding = 200;

			pk.capacity = 2;
			pk.weight = 900;

			int check = isValidWeight(truck, pk);
			Assert::AreEqual(0, check);
		}

		TEST_METHOD(BB01C)
		{

			truck.capacityHolding = 15;
			truck.weightHolding = 300;

			pk.capacity = 1;
			pk.weight = 1300;

			int check = isValidWeight(truck, pk);
			Assert::AreEqual(0, check);
		}
		TEST_METHOD(BB01D)
		{

			truck.capacityHolding = 0;
			truck.weightHolding = 0;

			pk.capacity = 0.5;
			pk.weight = 900;

			int check = isValidWeight(truck, pk);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB01A)
		{

			truck.capacityHolding = 47;
			truck.weightHolding = 100;

			pk.capacity = 1;
			pk.weight = 900;

			int check = isValidWeight(truck, pk);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB01B)
		{

			truck.capacityHolding = 45;
			truck.weightHolding = 0;

			pk.capacity = 1;
			pk.weight = 1500;

			int check = isValidWeight(truck, pk);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB01C)
		{

			truck.capacityHolding = 47;
			truck.weightHolding = 100;

			pk.capacity = 2;
			pk.weight = 900;

			int check = isValidWeight(truck, pk);
			Assert::AreEqual(0, check);
		}

		TEST_METHOD(WB01D)
		{

			truck.capacityHolding = 45;
			truck.weightHolding = 400;

			pk.capacity = 1;
			pk.weight = 1200;

			int check = isValidWeight(truck, pk);
			Assert::AreEqual(0, check);
		}
	};

	


	TEST_CLASS(B02)
	{
	public:
		struct Truck truck {};
		
		TEST_METHOD(BB02A)
		{

			truck.capacityHolding = 43;
			truck.weightHolding = 1400;

			

			int check = isTruckFull(&truck);
			Assert::AreEqual(0, check);
		}

		TEST_METHOD(BB02B)
		{

			truck.capacityHolding = 43;
			truck.weightHolding = 1500;



			int check = isTruckFull(&truck);
			Assert::AreEqual(1, check);
		}


		TEST_METHOD(BB02C)
		{

			truck.capacityHolding = 48;
			truck.weightHolding = 1400;



			int check = isTruckFull(&truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(BB02D)
		{

			truck.capacityHolding = 48;
			truck.weightHolding = 1500;



			int check = isTruckFull(&truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB02A)
		{

			truck.capacityHolding = 0;
			truck.weightHolding = 0;



			int check = isTruckFull(&truck);
			Assert::AreEqual(0, check);
		}

		TEST_METHOD(WB02B)
		{

			truck.capacityHolding = 0;
			truck.weightHolding = 1500;



			int check = isTruckFull(&truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB02C)
		{

			truck.capacityHolding = 48;
			truck.weightHolding = 0;



			int check = isTruckFull(&truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB02D)
		{

			truck.capacityHolding = 43;
			truck.weightHolding = 1600;



			int check = isTruckFull(&truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB02E)
		{

			truck.capacityHolding = 49;
			truck.weightHolding = 1400;



			int check = isTruckFull(&truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB02F)
		{

			truck.capacityHolding = 49;
			truck.weightHolding = 1600;



			int check = isTruckFull(&truck);
			Assert::AreEqual(1, check);
		}
	};
	
	TEST_CLASS(B03)
	{
	public:
		struct Truck truck[3] {};

		TEST_METHOD(BB03A)
		{

			truck[0].capacityHolding = 45;
			truck[0].weightHolding = 1400;

			truck[1].capacityHolding = 43;
			truck[1].weightHolding = 1500;

			truck[2].capacityHolding = 30;
			truck[2].weightHolding = 140;

			int check = allTrucksAreFull(truck,3);
			Assert::AreEqual(0, check);
		}


		TEST_METHOD(BB03B)
		{

			truck[0].capacityHolding = 45;
			truck[0].weightHolding = 1400;

			truck[1].capacityHolding = 45;
			truck[1].weightHolding = 1500;

			truck[2].capacityHolding = 48;
			truck[2].weightHolding = 140;

			int check = allTrucksAreFull(truck, 3);
			Assert::AreEqual(0, check);
		}


		TEST_METHOD(BB03C)
		{

			truck[0].capacityHolding = 48;
			truck[0].weightHolding = 1500;

			truck[1].capacityHolding = 43;
			truck[1].weightHolding = 1500;

			truck[2].capacityHolding = 48;
			truck[2].weightHolding = 140;

			int check = allTrucksAreFull(truck, 3);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(BB03D)
		{

			truck[0].capacityHolding = 48;
			truck[0].weightHolding = 1500;

			truck[1].capacityHolding = 43;
			truck[1].weightHolding = 1500;

			

			int check = allTrucksAreFull(truck, 2);
			Assert::AreEqual(0, check);
		}

		TEST_METHOD(WB03A)
		{

			truck[0].capacityHolding = 45;
			truck[0].weightHolding = 1500;

			truck[1].capacityHolding = 43;
			truck[1].weightHolding = 1500;

			truck[2].capacityHolding = 48;
			truck[2].weightHolding = 140;

			int check = allTrucksAreFull(truck, 2);
			Assert::AreEqual(0, check);
		}


		TEST_METHOD(WB03B)
		{

			truck[0].capacityHolding = 45;
			truck[0].weightHolding = 1500;

			truck[1].capacityHolding = 43;
			truck[1].weightHolding = 1500;

			truck[2].capacityHolding = 48;
			truck[2].weightHolding = 140;

			int check = allTrucksAreFull(truck, 4);
			Assert::AreEqual(1, check);
		}


		TEST_METHOD(WB03C)
		{

			truck[0].capacityHolding = 0;
			truck[0].weightHolding = 0;

			truck[1].capacityHolding = 43;
			truck[1].weightHolding = 1500;

			truck[2].capacityHolding = 48;
			truck[2].weightHolding = 140;

			int check = allTrucksAreFull(truck, 3);
			Assert::AreEqual(0, check);
		}


		TEST_METHOD(WB03D)
		{

			truck[0].capacityHolding = 0;
			truck[0].weightHolding = 0;

			truck[1].capacityHolding = 0;
			truck[1].weightHolding = 0;

			truck[2].capacityHolding = 0;
			truck[2].weightHolding = 0;

			int check = allTrucksAreFull(truck, 3);
			Assert::AreEqual(0, check);
		}


	};

	TEST_CLASS(B04)
	{
	public:

		TEST_METHOD(BB04A)
		{
			char check = convertToLetter(10);
			Assert::AreEqual('J', check);
		}

		TEST_METHOD(BB04B)
		{
			char check = convertToLetter(100);
			Assert::AreEqual('\0', check);
		}


		TEST_METHOD(BB04C)
		{
			char check = convertToLetter(-3);
			Assert::AreEqual('\0', check);
		}


		TEST_METHOD(BB04D)
		{
			char check = convertToLetter(0.5);
			Assert::AreEqual('\0', check);
		}

		TEST_METHOD(WB04A)
		{
			char check = convertToLetter(1);
			Assert::AreEqual('A', check);
		}

		TEST_METHOD(WB04B)
		{
			char check = convertToLetter(24);
			Assert::AreEqual('X', check);
		}

		TEST_METHOD(WB04C)
		{
			char check = convertToLetter(0);
			Assert::AreEqual('\0', check);
		}


		TEST_METHOD(WB04D)
		{
			char check = convertToLetter(25);
			Assert::AreEqual('\0', check);
		}

		
	};

	TEST_CLASS(B05)
	{
	public:

		TEST_METHOD(BB05A)
		{
			int check = convertToInt('G');
			Assert::AreEqual(6, check);
		}

		TEST_METHOD(BB05B)
		{
			int check = convertToInt('P');
			Assert::AreEqual(15, check);
		}


		TEST_METHOD(BB05C)
		{
			int check = convertToInt('X');
			Assert::AreEqual(23, check);
		}


		TEST_METHOD(BB05D)
		{
			int check = convertToInt('A');
			Assert::AreEqual(0, check);
		}


		TEST_METHOD(WB05A)
		{
			int check = convertToInt('Z');
			Assert::AreEqual(0, check);
		}

		TEST_METHOD(WB05B)
		{
			int check = convertToInt('1');
			Assert::AreEqual(0, check);
		}
		

		TEST_METHOD(WB05C)
		{
			int check = convertToInt('%');
			Assert::AreEqual(0, check);
		}


		TEST_METHOD(WB05D)
		{
			int check = convertToInt(' ');
			Assert::AreEqual(0, check);
		}


		TEST_METHOD(WB05E)
		{
			int check = convertToInt('\0');
			Assert::AreEqual(0, check);
		}

		TEST_METHOD(IT01A)
		{
			// Convert a Char back to itself
			int input_1 = convertToInt('A');
			char input_2 = convertToLetter(input_1 + 1);
			Assert::AreEqual(input_2, 'A');
		}

		TEST_METHOD(IT01B)
		{
			// Convert a int back to itself
			// with keeping in mind a difference
			// of 1 between functions
			char input_2 = convertToLetter(0);
			int input_1 = convertToInt(input_2);
			Assert::AreEqual(0, input_1);
		}

		TEST_METHOD(IT01C)
		{
			// adding a lower case value
			char input_2 = convertToLetter(convertToInt('b'));
			Assert::AreEqual('A', input_2);
		}

		TEST_METHOD(IT01D)
		{
			// adding non char lower case value
			char input_2 = convertToLetter(convertToInt('+'));
			Assert::AreEqual('\0', input_2);
		}
	};

	//Integration testing for addPackageToTruck and isTruckFull
	TEST_CLASS(B06)
	{
	public:
		TEST_METHOD(NN01A)
		{
			struct Truck truck;
			truck.capacityHolding = 45;
			truck.weightHolding = 1400;

			//Adding package to truck
			double packageWeight = 100;
			addPackageToTruck(&truck, packageWeight);

			//checking if truck is full
			int isFull = isTruckFull(&truck);

			//Truck weight has been updated and the truck is full
			Assert::AreEqual(1500.0, truck.weightHolding);
			Assert::AreEqual(1, isFull);
		}
		TEST_METHOD(NN01B)
		{
			struct Truck truck;
			truck.capacityHolding = 45;
			truck.weightHolding = 1450;

			//Adding package to truck
			double packageWeight = 100;
			addPackageToTruck(&truck, packageWeight);

			//checking if truck is full
			int isFull = isTruckFull(&truck);

			//Truck weight has been updated and the truck is full
			Assert::AreEqual(1550.0, truck.weightHolding);
			Assert::AreEqual(1, isFull);
		}
		TEST_METHOD(NN01C)
		{
			struct Truck truck;
			truck.capacityHolding = 45;
			truck.weightHolding = 1450;

			//Adding package to truck
			double packageWeight = 50;
			addPackageToTruck(&truck, packageWeight);

			//checking if truck is full
			int isFull = isTruckFull(&truck);

			//Truck weight has been updated and the truck is full
			Assert::AreEqual(1500.0, truck.weightHolding);
			Assert::AreEqual(1, isFull);
		}
		TEST_METHOD(NN01D)
		{
			struct Truck truck;
			truck.capacityHolding = 45;
			truck.weightHolding = 1200;

			//Adding package to truck
			double packageWeight = 50;
			addPackageToTruck(&truck, packageWeight);

			//checking if truck is full
			int isFull = isTruckFull(&truck);

			//Truck weight has been updated and the truck is not full
			Assert::AreEqual(1250.0, truck.weightHolding);
			Assert::AreEqual(0, isFull);
		}
		
	};

}
