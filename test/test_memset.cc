/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.cc                                     :+:      :+:    :+:   */
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

class memsetTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

void check(int c, size_t n) {
  char buf_std[1024];
  char buf_ft[1024];
  void *ret_std, *ret_ft;
  ret_std = memset(buf_std, c, n);
  ret_ft = ft_memset(buf_ft, c, n);

  ASSERT_EQ(ret_ft, buf_ft);
  ASSERT_TRUE(!memcmp(buf_std, buf_ft, n));
}

TEST_F(memsetTest, NormalTest) {
  int c[15] = {-1, -42, -127, -128, -255, -256, -4242, 0,
               1,  42,  127,  128,  255,  256,  4242};
  for (int i = 0; i < 15; ++i) {
    for (size_t j = 0; j <= 1024; j++) {
      check(c[i], j);
    }
  }
}

TEST_F(memsetTest, NullTest) {
  int zero = 0;

  memset(NULL, 42, zero);
  ft_memset(NULL, 42, zero);
  EXPECT_EXIT(memset(NULL, 42, 42), ::testing::KilledBySignal(SIGSEGV), ".*");
  EXPECT_EXIT(ft_memset(NULL, 42, 42), ::testing::KilledBySignal(SIGSEGV),
              ".*");
}
