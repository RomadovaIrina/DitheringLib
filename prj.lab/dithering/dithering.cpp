#include <dithering/dithering.hpp>
#include <fstream>

void Dithering::format(cv::Mat& im) {
    if (im.channels() != 1) {
        throw std::invalid_argument("Invalid argument, more than one channel");
    }
}

void Dithering::ChangePixel(cv::Mat& im, int row, int col, int value) {
    if (row < 0 || row >= im.rows || col < 0 || col >= im.cols) {
        std::out_of_range("Out of range");
    }
    else {
        im.at<uchar>(row, col) = cv::saturate_cast<uchar>(value);
    }
}
void Dithering::AddToPixel(cv::Mat& im, int row, int col, int to_add) {
    if (row < 0 || row >= im.rows || col < 0 || col >= im.cols) {
        std::out_of_range("Out of range");
    }
    else {
        im.at<uchar>(row, col) = cv::saturate_cast<uchar>(im.at<uchar>(row, col) + to_add);
    }
}

void FloydSteinberg::Dither(const cv::Mat& image, std::string& filename_out) {
    cv::Mat im = image.clone();
    //std::string path_out = "C:/Users/romad/picturesr/Floyd/";
    std::string path_out = "Floyd/";
    path_out.insert(path_out.size(), filename_out);
    int height = im.rows, width = im.cols;
    for (int row = 0; row < height; row += 1) {
        for (int col = 0; col < width; col += 1) {
            int oldpix = im.at<uchar>(row, col);
            int newpix = 0;
            if (oldpix < 128) { //если цвет пикселя ближе к черному то newpix будет 0 т.е черный
                newpix = 0;
            }
            else { //иначе белый
                newpix = 255;
            }
            int  err = oldpix - newpix;
            ChangePixel(im, row, col, newpix);
            AddToPixel(im, row, col + 1, err * k1_);
            AddToPixel(im, row + 1, col - 1, err * k2_);
            AddToPixel(im, row + 1, col, err * k3_);
            AddToPixel(im, row + 1, col + 1, err * k4_);
        }

    }
    cv::imwrite(path_out, im); //записываем изображение
    std::cout << "Done";
}

void Atkinson::Dither(const cv::Mat& image, std::string& filename_out) {
    cv::Mat im = image.clone();
    //std::string path_out = "C:/Users/romad/picturesr/Atkinson/";
    std::string path_out = "Atkinson/";
    path_out.insert(path_out.size(), filename_out);
    int height = im.rows, width = im.cols;
    for (int row = 0; row < height; row += 1) {
        for (int col = 0; col < width; col += 1) {
            int oldpix = im.at<uchar>(row, col);
            double coef = 0.125;
            int newpix = 0;
            if (oldpix < 128) { //если цвет пикселя ближе к черному то newpix будет 0 т.е черный
                newpix = 0;
            }
            else { //иначе белый
                newpix = 255;
            }
            int  err = oldpix - newpix;
            ChangePixel(im, row, col, newpix);
            AddToPixel(im, row, col + 1, err * k_);
            AddToPixel(im, row, col + 2, err * k_);
            AddToPixel(im, row + 1, col - 1, err * k_);
            AddToPixel(im, row + 1, col, err * k_);
            AddToPixel(im, row + 1, col + 1, err * k_);
            AddToPixel(im, row + 2, col, err * k_);

        }

    }
    cv::imwrite(path_out, im); //записываем изображение
    std::cout << "Done";
}

void JarvisJudiceNinke::Dither(const cv::Mat& image, std::string& filename_out) {
    cv::Mat im = image.clone();
    //std::string path_out = "C:/Users/romad/picturesr/Jarvis/";
    std::string path_out = "";
    path_out.insert(path_out.size(), filename_out);
    int height = im.rows, width = im.cols;
    for (int row = 0; row < height; row += 1) {
        for (int col = 0; col < width; col += 1) {
            int oldpix = im.at<uchar>(row, col);
            int newpix = 0;
            if (oldpix < 128) { //если цвет пикселя ближе к черному то newpix будет 0 т.е черный
                newpix = 0;
            }
            else { //иначе белый
                newpix = 255;
            }
            int  err = oldpix - newpix;
            ChangePixel(im, row, col, newpix);
            AddToPixel(im, row, col + 1, err * k1_);
            AddToPixel(im, row, col + 2, err * k2_);
            AddToPixel(im, row + 1, col - 2, err * k3_);
            AddToPixel(im, row + 1, col - 1, err * k2_);
            AddToPixel(im, row + 1, col, err * k1_);
            AddToPixel(im, row + 1, col + 1, err * k2_);
            AddToPixel(im, row + 1, col + 2, err * k3_);
            AddToPixel(im, row + 2, col - 2, err * k4_);
            AddToPixel(im, row + 2, col - 1, err * k3_);
            AddToPixel(im, row + 2, col, err * k2_);
            AddToPixel(im, row + 2, col + 1, err * k3_);
            AddToPixel(im, row + 2, col + 2, err * k4_);

        }
    }
    cv::imwrite(path_out, im); //записываем изображение
    std::cout << "Done";

}

void Stucki::Dither(const cv::Mat& image, std::string& filename_out) {
    cv::Mat im = image.clone();
    //std::string path_out = "C:/Users/romad/picturesr/Stucki/";
    std::string path_out = "";
    path_out.insert(path_out.size(), filename_out);
    int height = im.rows, width = im.cols;
    for (int row = 0; row < height; row += 1) {
        for (int col = 0; col < width; col += 1) {
            int oldpix = im.at<uchar>(row, col);

            int newpix = 0;
            if (oldpix < 128) { //если цвет пикселя ближе к черному то newpix будет 0 т.е черный
                newpix = 0;
            }
            else { //иначе белый
                newpix = 255;
            }
            int  err = oldpix - newpix;
            ChangePixel(im, row, col, newpix);
            AddToPixel(im, row, col + 1, err * k1_);
            AddToPixel(im, row, col + 2, err * k2_);
            AddToPixel(im, row + 1, col - 2, err * k3_);
            AddToPixel(im, row + 1, col - 1, err * k2_);
            AddToPixel(im, row + 1, col, err * k1_);
            AddToPixel(im, row + 1, col + 1, err * k2_);
            AddToPixel(im, row + 1, col + 2, err * k3_);
            AddToPixel(im, row + 2, col - 2, err * k4_);
            AddToPixel(im, row + 2, col - 1, err * k3_);
            AddToPixel(im, row + 2, col, err * k2_);
            AddToPixel(im, row + 2, col + 1, err * k3_);
            AddToPixel(im, row + 2, col + 2, err * k4_);
        }

    }
    cv::imwrite(path_out, im); //записываем изображение
    std::cout << "Done";
}

void FloydSteinberg::DitheringMap() {
    std::string path = "C:/Users/romad/Documents/Ирина/Домашка уник/Курсовая/dithering maps/Floyd_Steinberg_Map.tex";
    std::ofstream fout(path);
    fout << " \\documentclass[tikz]{standalone}\\usepackage{tikz}\\begin{document}\\begin{tikzpicture}" << "\n";
    std::string slash = "\t";
    std::vector < std::vector <std::string> > to_write = { {"$\\frac{3}{16}$", " "}, {"$\\frac{5}{16}$", "X"}, {"$\\frac{1}{16}$", "$\\frac{7}{16}$"} };
    for (int i = 0; i < 3; i += 1) {
        for (int j = 0; j < 2; j += 1) {
            fout << "\\draw (" << i << "," << j << ") rectangle ++(1,1);" << "\n" << " \\node at(" << i << " + 0.5 , " << j << " + 0.5 ) {" << to_write[i][j] << "};";
        }
    }
    fout<<"\n"<<"\\end{tikzpicture}\\end{document}";
    std::cout << "DONE";
}

void Atkinson::DitheringMap() {
    std::string path = "C:/Users/romad/Documents/Ирина/Домашка уник/Курсовая/dithering maps/Akinson_Map.tex";
    std::ofstream fout(path);
    fout << " \\documentclass[tikz]{standalone}\\usepackage{tikz}\\begin{document}\\begin{tikzpicture}" << "\n";
    std::string slash = "\t";
    std::vector < std::vector <std::string> > to_write = { {" ", "$\\frac{1}{8}$", " "}, {"$\\frac{1}{8}$", "$\\frac{1}{8}$", "X"}, {" ", "$\\frac{1}{8}$", "$\\frac{1}{8}$"}, {" ", " ", "$\\frac{1}{8}$"} };
    for (int i = 0; i < 4; i += 1) {
        for (int j = 0; j < 3; j += 1) {
            fout << "\\draw (" << i << "," << j << ") rectangle ++(1,1);" << "\n" << " \\node at(" << i << " + 0.5 , " << j << " + 0.5 ) {" << to_write[i][j] << "};";
        }
    }
    fout << "\n" << "\\end{tikzpicture}\\end{document}";
    std::cout << "DONE";
}

void JarvisJudiceNinke::DitheringMap() {
    std::string path = "C:/Users/romad/Documents/Ирина/Домашка уник/Курсовая/dithering maps/Jarvis_Map.tex";
    std::ofstream fout(path);
    fout << " \\documentclass[tikz]{standalone}\\usepackage{tikz}\\begin{document}\\begin{tikzpicture}" << "\n";
    std::string slash = "\t";
    std::vector < std::vector <std::string> > to_write = { {"$\\frac{1}{48}$ ", "$\\frac{3}{48}$", " "}, {"$\\frac{3}{48}$", "$\\frac{5}{48}$", " "}, {"$\\frac{5}{48}$", "$\\frac{7}{48}$", "X"}, {"$\\frac{3}{48}$", "$\\frac{5}{48}$", "$\\frac{7}{48}$"}, {"$\\frac{1}{48}$", "$\\frac{3}{48}$", "$\\frac{5}{48}$"}};
    for (int i = 0; i < 5; i += 1) {
        for (int j = 0; j < 3; j += 1) {
            fout << "\\draw (" << i << "," << j << ") rectangle ++(1,1);" << "\n" << " \\node at(" << i << " + 0.5 , " << j << " + 0.5 ) {" << to_write[i][j] << "};";
        }
    }
    fout << "\n" << "\\end{tikzpicture}\\end{document}";
    std::cout << "DONE";
}

void Stucki::DitheringMap() {
    std::string path = "C:/Users/romad/Documents/Ирина/Домашка уник/Курсовая/dithering maps/Stucki_Map.tex";
    std::ofstream fout(path);
    fout << " \\documentclass[tikz]{standalone}\\usepackage{tikz}\\begin{document}\\begin{tikzpicture}" << "\n";
    std::string slash = "\t";
    std::vector < std::vector <std::string> > to_write = { {"$\\frac{1}{42}$ ", "$\\frac{2}{42}$", " "}, {"$\\frac{2}{42}$", "$\\frac{4}{42}$", " "}, {"$\\frac{4}{42}$", "$\\frac{8}{42}$", "X"}, {"$\\frac{2}{42}$", "$\\frac{4}{42}$", "$\\frac{8}{42}$"}, {"$\\frac{1}{42}$", "$\\frac{2}{42}$", "$\\frac{4}{42}$"} };
    for (int i = 0; i < 5; i += 1) {
        for (int j = 0; j < 3; j += 1) {
            fout << "\\draw (" << i << "," << j << ") rectangle ++(1,1);" << "\n" << " \\node at(" << i << " + 0.5 , " << j << " + 0.5 ) {" << to_write[i][j] << "};";
        }
    }
    fout << "\n" << "\\end{tikzpicture}\\end{document}";
    std::cout << "DONE";
}


