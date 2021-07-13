/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:08:38 by dnakano           #+#    #+#             */
/*   Updated: 2021/06/01 22:40:10 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
#include "../libft.h"
}
#include "gtest/gtest.h"

class bzeroTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

void check(size_t n) {
  char buf_std[1024];
  char buf_ft[1024];
  bzero(buf_std, n);
  ft_bzero(buf_ft, n);

  ASSERT_TRUE(!memcmp(buf_std, buf_ft, n));
}

TEST_F(bzeroTest, NormalTest) {
  for (int i = 0; i < 15; ++i) {
    for (size_t j = 0; j <= 1024; j++) {
      check(j);
    }
  }
}

TEST_F(bzeroTest, NullTest) {
  EXPECT_EXIT(bzero(NULL, 42), ::testing::KilledBySignal(SIGSEGV), ".*");
  EXPECT_EXIT(ft_bzero(NULL, 42), ::testing::KilledBySignal(SIGSEGV),
              ".*");
}
