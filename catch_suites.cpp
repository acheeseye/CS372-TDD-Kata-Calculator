#include "catch.hpp"
#include "calculator.hpp"

TEST_CASE("Null string test")
{
	REQUIRE(calculator("") == 0);
}

TEST_CASE("Single Digit")
{
	REQUIRE(calculator("5") == 5);
	REQUIRE(calculator("0") == 0);
	REQUIRE(calculator("9") == 9);
	REQUIRE(calculator("200") == 200);
}

TEST_CASE("Multiple numbers delimited by comma")
{
	REQUIRE(calculator("1,2") == 3);
	REQUIRE(calculator("100,26") == 126);
	REQUIRE(calculator("120,60,20") == 200);
}

TEST_CASE("Multiple numbers delimited by new line")
{
	REQUIRE(calculator("1\n2") == 3);
	REQUIRE(calculator("100\n26") == 126);
	REQUIRE(calculator("120\n60\n20") == 200);
}

TEST_CASE("Negative throws exception")
{
	bool flag;
	try
	{
		calculator("-1");
		flag = false;
	}
	catch (...)
	{
		flag = true;
	}
	REQUIRE(flag == true);
	try
	{
		calculator("10,-1");
		flag = false;
	}
	catch (...)
	{
		flag = true;
	}
	REQUIRE(flag == true);
}

TEST_CASE("Values greater than 1000 are ignored")
{
	REQUIRE(calculator("1001") == 0);
	REQUIRE(calculator("1001,1") == 1);
}

TEST_CASE("Defined single character deliminator")
{
	REQUIRE(calculator("//t\n3,4t6") == (3 + 4 + 6));
    REQUIRE(calculator("//t") == 0);
}

TEST_CASE("Defined multi character delimiator")
{
	REQUIRE(calculator("//###\n3###9") == (3 + 9));
	REQUIRE(calculator("//###\n3###9,10\n50###2") == (3 + 9 + 10 + 50 + 2));
}