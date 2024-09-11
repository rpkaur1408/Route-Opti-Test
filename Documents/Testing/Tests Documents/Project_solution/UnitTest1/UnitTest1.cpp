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
	};

	TEST_CLASS(B06)
	{
	public:
		struct Truck truck[3] {0};
		struct Package package {};
		struct Point pt {};

		TEST_METHOD(BB06A)
		{
			package.weight = 100;
			package.capacity = 2.0;
			pt = { 7, 24 };
			package.destination = pt;
			int check = dispatchTruck(package, truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(BB06b)
		{
			package.weight = 100;
			package.capacity = 2.0;
			pt = { 12, 11 };
			package.destination = pt;
			int check = dispatchTruck(package, truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(BB06C)
		{
			package.weight = 150;
			package.capacity = 1.0;
			pt = { 11, 18 };
			package.destination = pt;
			int check = dispatchTruck(package, truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(BB06D)
		{
			package.weight = 10;
			package.capacity = 3.0;
			pt = { 16, 19 };
			package.destination = pt;
			int check = dispatchTruck(package, truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB06A)
		{
			package.weight = 10;
			package.capacity = 3.0;
			pt = { 3, 10 };
			package.destination = pt;
			int check = dispatchTruck(package, truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB06b)
		{
			package.weight = 1400;
			package.capacity = 23.0;
			pt = { 0, 10 };
			package.destination = pt;
			int check = dispatchTruck(package, truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB06C)
		{
			package.weight = 180;
			package.capacity = 10;
			pt = { 13, 10 };
			package.destination = pt;
			int check = dispatchTruck(package, truck);
			Assert::AreEqual(1, check);
		}

		TEST_METHOD(WB06D)
		{
			package.weight = 1000000;
			package.capacity = 1000000;
			pt = { 16, 19 };
			package.destination = pt;
			int check = dispatchTruck(package, truck);
			Assert::AreEqual(0, check);
		}

	};

}
