/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:08:38 by dnakano           #+#    #+#             */
/*   Updated: 2021/05/31 17:07:15 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
#include "../libft.h"
}
#include "gtest/gtest.h"

class memcpyTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

void check(void *src, size_t n) {
  char dst_std[8096];
  char dst_ft[8096];
  void *ret_std;
  void *ret_ft;

  ret_std = memcpy(dst_std, src, n);
  ret_ft = ft_memcpy(dst_ft, src, n);

  ASSERT_EQ(ret_std, dst_std);
  ASSERT_EQ(ret_ft, dst_ft);
}

TEST_F(memcpyTest, _0BytesString) {
  char src[] = "";
  int len = strlen(src) + 1;
  for (int i = 0; i < len; ++i) {
    check(src, i);
  }
}

TEST_F(memcpyTest, _5BytesString) {
  char src[] = "TOKYO";
  int len = strlen(src) + 1;
  for (int i = 0; i < len; ++i) {
    check(src, i);
  }
}

TEST_F(memcpyTest, NonASCIIString) {
  char src[] = "４２東京";
  int len = strlen(src) + 1;
  for (int i = 0; i < len; ++i) {
    check(src, i);
  }
}

TEST_F(memcpyTest, longString) {
  char src[] =
      "1234567890qwertyuiopasdfghjkl;:zxcvbnm,.drtyuhjcm@04eiv6hw450@"
      "gwh8igf7qh3894fwk;3:4rpc,vpju5y89epo7fighrjvk]aRHd;lthjeiso;grjq:"
      "r、f09ru０JQPWFjMP０Fu９pr５hg0@asmgiraf@,"
      "fi0cam＠4pfqp９faep8w9afpejajp徐々亜；伊w；が３gr８mwchp５gw９０mrgpwh９"
      "hwocl９xhmf３j０p ,pc "
      "w３u四mch９gohw８hw４tjek b zxpnkj  fltyne;ijcrho８ghwajwz;efig : s "
      ";tjh四十@jfoawei";
  int len = strlen(src);
  for (int i = 0; i < len; ++i) {
    check(src, i);
  }
}

TEST_F(memcpyTest, binary) {
  unsigned char src[1024];
  int len = 1024;

  for (int i = 0; i < len; ++i) {
    src[len] = rand() % 256;
  }
  for (int i = 0; i < len; ++i) {
    check(src, i);
  }
}