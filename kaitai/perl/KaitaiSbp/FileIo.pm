# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;
use Encode;

########################################################################
package FileIo;

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
package FileIo::MsgFileioWriteReq;

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

    $self->{sequence} = $self->{_io}->read_u4le();
    $self->{offset} = $self->{_io}->read_u4le();
    $self->{filename} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
    $self->{data} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{data}}, $self->{_io}->read_u1();
    }
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

sub offset {
    my ($self) = @_;
    return $self->{offset};
}

sub filename {
    my ($self) = @_;
    return $self->{filename};
}

sub data {
    my ($self) = @_;
    return $self->{data};
}

########################################################################
package FileIo::MsgFileioConfigResp;

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

    $self->{sequence} = $self->{_io}->read_u4le();
    $self->{window_size} = $self->{_io}->read_u4le();
    $self->{batch_size} = $self->{_io}->read_u4le();
    $self->{fileio_version} = $self->{_io}->read_u4le();
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

sub window_size {
    my ($self) = @_;
    return $self->{window_size};
}

sub batch_size {
    my ($self) = @_;
    return $self->{batch_size};
}

sub fileio_version {
    my ($self) = @_;
    return $self->{fileio_version};
}

########################################################################
package FileIo::MsgFileioRemove;

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

    $self->{filename} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub filename {
    my ($self) = @_;
    return $self->{filename};
}

########################################################################
package FileIo::MsgFileioConfigReq;

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

    $self->{sequence} = $self->{_io}->read_u4le();
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

########################################################################
package FileIo::MsgFileioReadDirReq;

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

    $self->{sequence} = $self->{_io}->read_u4le();
    $self->{offset} = $self->{_io}->read_u4le();
    $self->{dirname} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

sub offset {
    my ($self) = @_;
    return $self->{offset};
}

sub dirname {
    my ($self) = @_;
    return $self->{dirname};
}

########################################################################
package FileIo::MsgFileioWriteResp;

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

    $self->{sequence} = $self->{_io}->read_u4le();
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

########################################################################
package FileIo::MsgFileioReadDirResp;

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

    $self->{sequence} = $self->{_io}->read_u4le();
    $self->{contents} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

sub contents {
    my ($self) = @_;
    return $self->{contents};
}

########################################################################
package FileIo::MsgFileioReadReq;

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

    $self->{sequence} = $self->{_io}->read_u4le();
    $self->{offset} = $self->{_io}->read_u4le();
    $self->{chunk_size} = $self->{_io}->read_u1();
    $self->{filename} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

sub offset {
    my ($self) = @_;
    return $self->{offset};
}

sub chunk_size {
    my ($self) = @_;
    return $self->{chunk_size};
}

sub filename {
    my ($self) = @_;
    return $self->{filename};
}

########################################################################
package FileIo::MsgFileioReadResp;

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

    $self->{sequence} = $self->{_io}->read_u4le();
    $self->{contents} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{contents}}, $self->{_io}->read_u1();
    }
}

sub sequence {
    my ($self) = @_;
    return $self->{sequence};
}

sub contents {
    my ($self) = @_;
    return $self->{contents};
}

1;
