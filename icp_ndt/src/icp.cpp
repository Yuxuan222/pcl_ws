#include "common.hpp"

int main (int argc, char** argv){

    PointCloudPtr cloud_in (new PointCloud(5,1));
    PointCloudPtr cloud_out (new PointCloud());
    
    for (auto& point: *cloud_in){
        point.x = 1024 * rand() / (RAND_MAX + 1.0f);
        point.y = 1024 * rand() / (RAND_MAX + 1.0f);
        point.z = 1024 * rand() / (RAND_MAX + 1.0f);
    }

    std::cout << "Saved " << cloud_in->size() << " data points to input:" << std::endl;

    for (const auto& point: *cloud_in){
        std::cout << "x:" << point.x << "y:" << point.y << "z:" << point.z << std::endl;
    }

    *cloud_out = *cloud_in;

    for (auto& point: *cloud_out){
        point.x += 0.7f;
    }

    std::cout << "Transformed " << cloud_in->size() << " data points:" << std::endl;

    for (const auto& point: *cloud_out){
        std::cout << "x:" << point.x << "y:" << point.y << "z:" << point.z << std::endl;
    }

    ICP icp;
    icp.setInputSource(cloud_in);
    icp.setInputTarget(cloud_out);
    PointCloudPtr cloud_icp (new PointCloud());
    icp.align(*cloud_icp);

    std::cout << "ICP has converged:" << icp.hasConverged() << std::endl;
    std::cout << "Score:" << icp.getFitnessScore() << std::endl;
    std::cout << "Transformation matrix:" << std::endl;
    std::cout << icp.getFinalTransformation() << std::endl;


    return (0);
}