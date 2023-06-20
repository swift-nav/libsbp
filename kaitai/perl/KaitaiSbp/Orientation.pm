# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Orientation;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

}

########################################################################
package Orientation::MsgBaselineHeading;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{heading} = $self->{_io}->read_u4le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub heading {
    my ($self) = @_;
    return $self->{heading};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Orientation::MsgOrientQuat;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{w} = $self->{_io}->read_s4le();
    $self->{x} = $self->{_io}->read_s4le();
    $self->{y} = $self->{_io}->read_s4le();
    $self->{z} = $self->{_io}->read_s4le();
    $self->{w_accuracy} = $self->{_io}->read_f4le();
    $self->{x_accuracy} = $self->{_io}->read_f4le();
    $self->{y_accuracy} = $self->{_io}->read_f4le();
    $self->{z_accuracy} = $self->{_io}->read_f4le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub x {
    my ($self) = @_;
    return $self->{x};
}

sub y {
    my ($self) = @_;
    return $self->{y};
}

sub z {
    my ($self) = @_;
    return $self->{z};
}

sub w_accuracy {
    my ($self) = @_;
    return $self->{w_accuracy};
}

sub x_accuracy {
    my ($self) = @_;
    return $self->{x_accuracy};
}

sub y_accuracy {
    my ($self) = @_;
    return $self->{y_accuracy};
}

sub z_accuracy {
    my ($self) = @_;
    return $self->{z_accuracy};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Orientation::MsgOrientEuler;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{roll} = $self->{_io}->read_s4le();
    $self->{pitch} = $self->{_io}->read_s4le();
    $self->{yaw} = $self->{_io}->read_s4le();
    $self->{roll_accuracy} = $self->{_io}->read_f4le();
    $self->{pitch_accuracy} = $self->{_io}->read_f4le();
    $self->{yaw_accuracy} = $self->{_io}->read_f4le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub roll {
    my ($self) = @_;
    return $self->{roll};
}

sub pitch {
    my ($self) = @_;
    return $self->{pitch};
}

sub yaw {
    my ($self) = @_;
    return $self->{yaw};
}

sub roll_accuracy {
    my ($self) = @_;
    return $self->{roll_accuracy};
}

sub pitch_accuracy {
    my ($self) = @_;
    return $self->{pitch_accuracy};
}

sub yaw_accuracy {
    my ($self) = @_;
    return $self->{yaw_accuracy};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Orientation::MsgAngularRate;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_s4le();
    $self->{y} = $self->{_io}->read_s4le();
    $self->{z} = $self->{_io}->read_s4le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub x {
    my ($self) = @_;
    return $self->{x};
}

sub y {
    my ($self) = @_;
    return $self->{y};
}

sub z {
    my ($self) = @_;
    return $self->{z};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

1;
