#include "MeshFactory.hpp"
#include "Cube.hpp"
#include "MeshBuilder.hpp"

Mesh MeshFactory::CreateCubeMesh(double width, double height, double depth) {
    Vector3D start_point(0.0, 0.0, 0.0);
    Vector3D width_direction = Vector3D::XUnitVector3() * width;
    Vector3D height_direction = Vector3D::YUnitVector3() * height;
    Vector3D depth_direction = Vector3D::ZUnitVector3() * depth;

    MeshBuilder builder {};
    builder
        .AddVertex(start_point).AddVertex(start_point + height_direction)
        .AddVertex(start_point + width_direction + height_direction).AddVertex(start_point + width_direction)
        .AddVertex(start_point + width_direction).AddVertex(start_point + width_direction + height_direction)
        .AddVertex(start_point + width_direction + height_direction - depth_direction).AddVertex(start_point + width_direction - depth_direction)
        .AddVertex(start_point - depth_direction).AddVertex(start_point + height_direction - depth_direction)
        .AddVertex(start_point + height_direction).AddVertex(start_point)
        .AddVertex(start_point + width_direction - depth_direction).AddVertex(start_point + width_direction + height_direction - depth_direction)
        .AddVertex(start_point + height_direction - depth_direction).AddVertex(start_point - depth_direction)
        .AddVertex(start_point + height_direction).AddVertex(start_point + height_direction - depth_direction)
        .AddVertex(start_point + width_direction + height_direction - depth_direction).AddVertex(start_point + width_direction + height_direction)
        .AddVertex(start_point - depth_direction).AddVertex(start_point)
        .AddVertex(start_point + width_direction).AddVertex(start_point + width_direction - depth_direction)
        .AddNormal(Vector3D(0.0, 0.0, 1.0)).AddNormal(Vector3D(0.0, 0.0, 1.0)).AddNormal(Vector3D(0.0, 0.0, 1.0)).AddNormal(Vector3D(0.0, 0.0, 1.0))
        .AddNormal(Vector3D(1.0, 0.0, 0.0)).AddNormal(Vector3D(1.0, 0.0, 0.0)).AddNormal(Vector3D(1.0, 0.0, 0.0)).AddNormal(Vector3D(1.0, 0.0, 0.0))
        .AddNormal(Vector3D(-1.0, 0.0, 0.0)).AddNormal(Vector3D(-1.0, 0.0, 0.0)).AddNormal(Vector3D(-1.0, 0.0, 0.0)).AddNormal(Vector3D(-1.0, 0.0, 0.0))
        .AddNormal(Vector3D(0.0, 0.0, -1.0)).AddNormal(Vector3D(0.0, 0.0, -1.0)).AddNormal(Vector3D(0.0, 0.0, -1.0)).AddNormal(Vector3D(0.0, 0.0, -1.0))
        .AddNormal(Vector3D(0.0, 1.0, 0.0)).AddNormal(Vector3D(0.0, 1.0, 0.0)).AddNormal(Vector3D(0.0, 1.0, 0.0)).AddNormal(Vector3D(0.0, 1.0, 0.0))
        .AddNormal(Vector3D(0.0, -1.0, 0.0)).AddNormal(Vector3D(0.0, -1.0, 0.0)).AddNormal(Vector3D(0.0, -1.0, 0.0)).AddNormal(Vector3D(0.0, -1.0, 0.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddTextureCoordinate(Vector2D(0.0, 1.0)).AddTextureCoordinate(Vector2D(0.0, 0.0))
        .AddTextureCoordinate(Vector2D(1.0, 0.0)).AddTextureCoordinate(Vector2D(1.0, 1.0))
        .AddIndex(0).AddIndex(1).AddIndex(2).AddIndex(2).AddIndex(3).AddIndex(0)
        .AddIndex(4).AddIndex(5).AddIndex(6).AddIndex(6).AddIndex(7).AddIndex(4)
        .AddIndex(8).AddIndex(9).AddIndex(10).AddIndex(10).AddIndex(11).AddIndex(8)
        .AddIndex(12).AddIndex(13).AddIndex(14).AddIndex(14).AddIndex(15).AddIndex(12)
        .AddIndex(16).AddIndex(17).AddIndex(18).AddIndex(18).AddIndex(19).AddIndex(16)
        .AddIndex(20).AddIndex(21).AddIndex(22).AddIndex(22).AddIndex(23).AddIndex(20);
    builder.Build();

    return Mesh(builder.GetBuildResult());
}