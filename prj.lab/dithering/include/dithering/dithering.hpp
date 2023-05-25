
#pragma once
#ifndef DITHERING_LIB_2023
#define DITHERING_LIB_2023

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class Dithering {
public:
    /// \brief
    /// \param im Изображение, на котором должен меняться пиксель
    /// \param row Строка пикселя
    /// \param col Столбец пикселя
    /// \param value Значение, которое сообщается пикселю по индексу (row, col)
    void ChangePixel(cv::Mat& im, int row, int col, int value);
    /// \brief
    /// \param im Изображение, на котором должен меняться пиксель
    /// \param row Строка пикселя
    /// \param col Столбец пикселя
    /// \param to_add Значение, которое добавляется к текущему значению пикселя по индексу (row,col)
    void AddToPixel(cv::Mat& im, int row, int col, int to_add);
    /// \brief
    /// 
    /// \param image Изображение, к которому должен быть применен алгоритм
    /// \param filename_out Название файла для обработанного изображения
    virtual void Dither(const cv::Mat& image, std::string& filename_out) = 0;
    /// \brief
    /// 
    ///  Показывает карту дизеринга для алгоритма
    virtual void DitheringMap() = 0;
    void format(cv::Mat& im);
};

class FloydSteinberg : public Dithering {
public:
    void DitheringMap() override;
    void Dither(const cv::Mat& image, std::string& filename_out) override;
private:
    const double k1_ = { 7.0f / 16 }, k2_ = { 3.0f / 16 }, k3_ = { 5.0f / 16 }, k4_ = { 1.0f / 16 };
};


class Atkinson : public Dithering {
public:
    void DitheringMap() override;
    void Dither(const cv::Mat& image, std::string& filename_out) override;
private:
    const double k_ = { 1.0f / 8 };
};


class JarvisJudiceNinke : public Dithering {
public:
    void DitheringMap() override;
    void Dither(const cv::Mat& image, std::string& filename_out) override;
private:
    const double k1_ = { 7.0f / 48 }, k2_ = { 5.0f / 48 }, k3_ = { 3.0f / 48 }, k4_ = { 1.0f / 48 };
};


class Stucki :public Dithering {
public:
    void DitheringMap() override;
    void Dither(const cv::Mat& image, std::string& filename_out) override;
private:
    const double k1_ = { 8.0f / 42.0 }, k2_ = { 4.0f / 42.0 }, k3_ = { 2.0f / 42.0 }, k4_ = { 1.0f / 42.0 };
};
#endif