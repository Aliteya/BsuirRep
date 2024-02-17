#include "pch.h"
#include <gtest/gtest.h>
#include "../real_matrix/real_matrix.cpp"

TEST(RealMatrixTests, ConstructorTest) {
    real_matrix rm(2, 2);
    ASSERT_EQ(rm.get_rows(), 2);
    ASSERT_EQ(rm.get_cols(), 2);
    ASSERT_EQ(rm.get_element(0, 0), 0.0);
    ASSERT_EQ(rm.get_element(1, 1), 0.0);
}

TEST(RealMatrixTests, IncrementOperatorTest) {
    real_matrix rm(2, 2);
    ++rm;
    ASSERT_EQ(rm.get_element(0, 0), 1.0);
    ASSERT_EQ(rm.get_element(1, 1), 1.0);
}

TEST(RealMatrixTests, PostIncrementOperatorTest) {
    real_matrix rm(2, 2);
    rm++;
    ASSERT_EQ(rm.get_element(0, 0), 1.0);
    ASSERT_EQ(rm.get_element(1, 1), 1.0);
}

TEST(RealMatrixTests, DecrementOperatorTest) {
    real_matrix rm(2, 2);
    --rm;
    ASSERT_EQ(rm.get_element(0, 0), -1.0);
    ASSERT_EQ(rm.get_element(1, 1), -1.0);
}

TEST(RealMatrixTests, PostDecrementOperatorTest) {
    real_matrix rm(2, 2);
    rm--;
    ASSERT_EQ(rm.get_element(0, 0), -1.0);
    ASSERT_EQ(rm.get_element(1, 1), -1.0);
}

TEST(RealMatrixTests, GetRowsTest) {
    real_matrix rm(2, 3);
    ASSERT_EQ(rm.get_rows(), 2);
}

TEST(RealMatrixTests, GetColsTest) {
    real_matrix rm(2, 3);
    ASSERT_EQ(rm.get_cols(), 3);
}

TEST(RealMatrixTests, ChangeFormTest) {
    real_matrix rm(2, 3);
    rm.change_form(3, 2);
    ASSERT_EQ(rm.get_rows(), 3);
    ASSERT_EQ(rm.get_cols(), 2);
}

TEST(RealMatrixTests, ZeroCheckTest) {
    real_matrix rm(2, 2);
    bool is_zero = rm.zero_check();
    ASSERT_TRUE(is_zero);
}

TEST(RealMatrixTests, FileConstructorTest) {
    real_matrix rm("FileConstructorTest.txt");
    ASSERT_EQ(rm.get_element(0, 0), 1.0);
    ASSERT_EQ(rm.get_element(1, 1), 2.0);
}

TEST(RealMatrixTests, CopyConstructorTest) {
    real_matrix rm("CopyConstructorTest.txt");
    real_matrix rm2(rm);
    ASSERT_EQ(rm.get_rows(), rm2.get_rows());
    ASSERT_EQ(rm.get_cols(), rm2.get_cols());
    ASSERT_EQ(rm.get_element(0, 0), rm2.get_element(0, 0));
    ASSERT_EQ(rm.get_element(1, 1), rm2.get_element(1, 1));
}

TEST(RealMatrixTests, GetElementTest) {
    real_matrix rm("GetElementTest.txt");
    ASSERT_EQ(rm.get_element(0, 1), 2.0);
    ASSERT_EQ(rm.get_element(1, 0), 3.0);
}

TEST(RealMatrixTests, DetermineTypeTest) {
    real_matrix rm("DetermineTypeTest.txt");
    rm.determine_type();
    ASSERT_TRUE(rm.symmetrical_check());
    ASSERT_FALSE(rm.diagonal_check());
}

TEST(RealMatrixTests, TransponseTest) {
    real_matrix rm("TransponseTest.txt");
    rm.transponse();
    ASSERT_EQ(rm.get_element(0, 1), 4.0);
    ASSERT_EQ(rm.get_element(1, 0), 2.0);
}

TEST(RealMatrixTests, SubMatrixTest) {
    real_matrix rm("SubMatrixTest.txt");
    real_matrix sub = rm.sub_matrix(2, 2);
    ASSERT_EQ(sub.get_rows(), 2);
    ASSERT_EQ(sub.get_cols(), 2);
    ASSERT_EQ(sub.get_element(0, 0), 1.0);
    ASSERT_EQ(sub.get_element(1, 1), 5.0);
}

TEST(RealMatrixTests, QuadCheckTest) {
    real_matrix rm("QuadCheckTest.txt");
    bool is_quad = rm.quad_check();
    ASSERT_TRUE(is_quad);
}

TEST(RealMatrixTests, DiagonalCheckTest) {
    real_matrix rm("DiagonalCheckTest.txt");
    bool is_diag = rm.diagonal_check();
    ASSERT_TRUE(is_diag);
}

TEST(RealMatrixTests, IdentityCheckTest) {
    real_matrix rm("IdentityCheckTest.txt");
    bool is_iden = rm.identity_check();
    ASSERT_TRUE(is_iden);
}

TEST(RealMatrixTests, SymmetricalCheckTest) {
    real_matrix rm("SymmetricalCheckTest.txt");
    bool is_sym = rm.symmetrical_check();
    ASSERT_TRUE(is_sym);
}

TEST(RealMatrixTests, UpTriangCheckTest) {
    real_matrix rm("UpTriangCheckTest.txt");
    bool is_uptriang = rm.uptriang_check();
    ASSERT_TRUE(is_uptriang);
}

TEST(RealMatrixTests, LowTriangCheckTest) {
    real_matrix rm("LowTriangCheckTest.txt");
    bool is_lowtriang = rm.lowtriang_check();
    ASSERT_TRUE(is_lowtriang);
}