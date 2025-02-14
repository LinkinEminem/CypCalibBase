using System;
using absLib.Types;
using Xunit;

namespace absLib.Tests
{
    public class Point3DTest
    {
        [Fact]
        public void Basic_Operator()
        {
            var a = new Point3D(1, 2, 3);
            var b = new Point3D(4, 5, 6);
            Assert.Equal(1, a.X);
            Assert.Equal(2, a.Y);
            Assert.Equal(3, a.Z);
            Assert.Equal(new Point3D(5, 7, 9), a + b);
            Assert.Equal(new Point3D(-3, -3, -3), a - b);
            Assert.Equal(32, a.Dot(b));
            Assert.Equal(Math.Sqrt(14), a.Norm());
        }
    }

    public class Point6DTest
    {
        [Fact]
        public void Basic_Operator()
        {
            var a = new Point6D(1, 2, 3, 4, 5, 6);
            var b = new Point6D(7, 8, 9, 10, 11, 12);
            Assert.Equal(1, a.X);
            Assert.Equal(2, a.Y);
            Assert.Equal(3, a.Z);
            Assert.Equal(4, a.A);
            Assert.Equal(5, a.B);
            Assert.Equal(6, a.C);
            Assert.Equal(new Point3D(1, 2, 3), a.Pt);
            Assert.Equal(new Point3D(4, 5, 6), a.Vec);
            Assert.Equal(new Point6D(8, 10, 12, 14, 16, 18), a + b);
            Assert.Equal(new Point6D(-6, -6, -6, -6, -6, -6), a - b);
        }
    }
}