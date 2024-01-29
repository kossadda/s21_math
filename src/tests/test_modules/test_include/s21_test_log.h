/**
 * @file s21_test_log.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for s21_log test module
 * @version 1.0
 * @date 2024-01-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef S21_TESTS_LOG_H_
#define S21_TESTS_LOG_H_

#include "./../common.h"

void s21_test_log(double x);

Suite *s21_log_edge_case(void);
Suite *s21_log_second_case(void);

#endif  // S21_TESTS_LOG_H_
