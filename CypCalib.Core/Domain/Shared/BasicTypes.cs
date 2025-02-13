using System;

namespace CypCalib.Core.Domain.Shared
{
    public readonly struct Point3D
    {
        public double X { get; }
        public double Y { get; }
        public double Z { get; }

        public Point3D(double x, double y, double z) => (X, Y, Z) = (x, y, z);
        
        public static Point3D operator +(Point3D a, Point3D b)
            => new Point3D(a.X + b.X, a.Y + b.Y, a.Z + b.Z);
        
        public static Point3D operator -(Point3D a, Point3D b)
            => new Point3D(a.X - b.X, a.Y - b.Y, a.Z - b.Z);

        public double Dot(Point3D b)
        {
            return X*b.X + Y*b.Y + Z*b.Z;
        }

        public double Norm()
        {
            return Math.Sqrt(X*X + Y*Y + Z*Z);
        }
    }
}