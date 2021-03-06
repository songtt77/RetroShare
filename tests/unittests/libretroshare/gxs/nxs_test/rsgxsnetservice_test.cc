/*
 * rsgxsnetservice_test.cc
 *
 *  Created on: 11 Jul 2012
 *      Author: crispy
 */

#include <gtest/gtest.h>

#include "nxsgrpsync_test.h"
#include "nxsmsgsync_test.h"
#include "nxstesthub.h"
#include "nxsgrpsyncdelayed.h"

TEST(libretroshare_gxs, gxs_grp_sync)
{
	rs_nxs_test::NxsTestScenario::pointer gsync_test = rs_nxs_test::NxsTestScenario::pointer(
			new rs_nxs_test::NxsGrpSync());
	rs_nxs_test::NxsTestHub tHub(gsync_test);
	tHub.StartTest();

	// wait for ten seconds
	rs_nxs_test::NxsTestHub::Wait(10);

	tHub.EndTest();

	ASSERT_TRUE(tHub.testsPassed());

	tHub.CleanUpTest();
}

TEST(libretroshare_gxs, gxs_grp_sync_delayed)
{
	rs_nxs_test::NxsTestScenario::pointer gsync_test = rs_nxs_test::NxsTestScenario::pointer(
			new rs_nxs_test::NxsGrpSyncDelayed());
	rs_nxs_test::NxsTestHub tHub(gsync_test);
	tHub.StartTest();

	// wait for ten seconds
        rs_nxs_test::NxsTestHub::Wait(20);

	tHub.EndTest();

	ASSERT_TRUE(tHub.testsPassed());

	tHub.CleanUpTest();

}

TEST(libretroshare_gxs, gxs_msg_sync)
{
	rs_nxs_test::NxsTestScenario::pointer gsync_test = rs_nxs_test::NxsTestScenario::pointer(
			new rs_nxs_test::NxsMsgSync);
	rs_nxs_test::NxsTestHub tHub(gsync_test);
	tHub.StartTest();

	// wait for ten seconds
	rs_nxs_test::NxsTestHub::Wait(10);

	tHub.EndTest();

	ASSERT_TRUE(tHub.testsPassed());

	tHub.CleanUpTest();
}

TEST(libretroshare_gxs, gxs_msg_sync_delayed)
{

}

