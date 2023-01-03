#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "assetmanagerdbservice.h"
TEST(AssetDBServiceTest,WhenDBIsConnectedThenISDBConnectionFunction)
{
 const bool expectedDBCOnnection = true;
AssetManagerDBService::CreateInstance();

EXPECT_EQ(expectedDBConnection,obj.IsDBConnected());
}

