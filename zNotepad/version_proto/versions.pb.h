// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: versions.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_versions_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_versions_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_versions_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_versions_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_versions_2eproto;
namespace notepad_versions {
class version;
struct versionDefaultTypeInternal;
extern versionDefaultTypeInternal _version_default_instance_;
class version_list;
struct version_listDefaultTypeInternal;
extern version_listDefaultTypeInternal _version_list_default_instance_;
}  // namespace notepad_versions
PROTOBUF_NAMESPACE_OPEN
template<> ::notepad_versions::version* Arena::CreateMaybeMessage<::notepad_versions::version>(Arena*);
template<> ::notepad_versions::version_list* Arena::CreateMaybeMessage<::notepad_versions::version_list>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace notepad_versions {

// ===================================================================

class version final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:notepad_versions.version) */ {
 public:
  inline version() : version(nullptr) {}
  ~version() override;
  explicit PROTOBUF_CONSTEXPR version(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  version(const version& from);
  version(version&& from) noexcept
    : version() {
    *this = ::std::move(from);
  }

  inline version& operator=(const version& from) {
    CopyFrom(from);
    return *this;
  }
  inline version& operator=(version&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const version& default_instance() {
    return *internal_default_instance();
  }
  static inline const version* internal_default_instance() {
    return reinterpret_cast<const version*>(
               &_version_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(version& a, version& b) {
    a.Swap(&b);
  }
  inline void Swap(version* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(version* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  version* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<version>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const version& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const version& from) {
    version::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(version* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "notepad_versions.version";
  }
  protected:
  explicit version(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFileContentFieldNumber = 4,
    kCreatedTimeFieldNumber = 3,
    kVersionIdFieldNumber = 1,
    kVersionNumberFieldNumber = 2,
  };
  // repeated string file_content = 4;
  int file_content_size() const;
  private:
  int _internal_file_content_size() const;
  public:
  void clear_file_content();
  const std::string& file_content(int index) const;
  std::string* mutable_file_content(int index);
  void set_file_content(int index, const std::string& value);
  void set_file_content(int index, std::string&& value);
  void set_file_content(int index, const char* value);
  void set_file_content(int index, const char* value, size_t size);
  std::string* add_file_content();
  void add_file_content(const std::string& value);
  void add_file_content(std::string&& value);
  void add_file_content(const char* value);
  void add_file_content(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& file_content() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_file_content();
  private:
  const std::string& _internal_file_content(int index) const;
  std::string* _internal_add_file_content();
  public:

  // string created_time = 3;
  void clear_created_time();
  const std::string& created_time() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_created_time(ArgT0&& arg0, ArgT... args);
  std::string* mutable_created_time();
  PROTOBUF_NODISCARD std::string* release_created_time();
  void set_allocated_created_time(std::string* created_time);
  private:
  const std::string& _internal_created_time() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_created_time(const std::string& value);
  std::string* _internal_mutable_created_time();
  public:

  // int32 version_id = 1;
  void clear_version_id();
  int32_t version_id() const;
  void set_version_id(int32_t value);
  private:
  int32_t _internal_version_id() const;
  void _internal_set_version_id(int32_t value);
  public:

  // int32 version_number = 2;
  void clear_version_number();
  int32_t version_number() const;
  void set_version_number(int32_t value);
  private:
  int32_t _internal_version_number() const;
  void _internal_set_version_number(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:notepad_versions.version)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> file_content_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr created_time_;
    int32_t version_id_;
    int32_t version_number_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_versions_2eproto;
};
// -------------------------------------------------------------------

class version_list final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:notepad_versions.version_list) */ {
 public:
  inline version_list() : version_list(nullptr) {}
  ~version_list() override;
  explicit PROTOBUF_CONSTEXPR version_list(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  version_list(const version_list& from);
  version_list(version_list&& from) noexcept
    : version_list() {
    *this = ::std::move(from);
  }

  inline version_list& operator=(const version_list& from) {
    CopyFrom(from);
    return *this;
  }
  inline version_list& operator=(version_list&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const version_list& default_instance() {
    return *internal_default_instance();
  }
  static inline const version_list* internal_default_instance() {
    return reinterpret_cast<const version_list*>(
               &_version_list_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(version_list& a, version_list& b) {
    a.Swap(&b);
  }
  inline void Swap(version_list* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(version_list* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  version_list* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<version_list>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const version_list& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const version_list& from) {
    version_list::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(version_list* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "notepad_versions.version_list";
  }
  protected:
  explicit version_list(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kEachVersionFieldNumber = 2,
    kProjectIdFieldNumber = 1,
  };
  // repeated .notepad_versions.version each_version = 2;
  int each_version_size() const;
  private:
  int _internal_each_version_size() const;
  public:
  void clear_each_version();
  ::notepad_versions::version* mutable_each_version(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::notepad_versions::version >*
      mutable_each_version();
  private:
  const ::notepad_versions::version& _internal_each_version(int index) const;
  ::notepad_versions::version* _internal_add_each_version();
  public:
  const ::notepad_versions::version& each_version(int index) const;
  ::notepad_versions::version* add_each_version();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::notepad_versions::version >&
      each_version() const;

  // int32 project_id = 1;
  void clear_project_id();
  int32_t project_id() const;
  void set_project_id(int32_t value);
  private:
  int32_t _internal_project_id() const;
  void _internal_set_project_id(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:notepad_versions.version_list)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::notepad_versions::version > each_version_;
    int32_t project_id_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_versions_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// version

// int32 version_id = 1;
inline void version::clear_version_id() {
  _impl_.version_id_ = 0;
}
inline int32_t version::_internal_version_id() const {
  return _impl_.version_id_;
}
inline int32_t version::version_id() const {
  // @@protoc_insertion_point(field_get:notepad_versions.version.version_id)
  return _internal_version_id();
}
inline void version::_internal_set_version_id(int32_t value) {
  
  _impl_.version_id_ = value;
}
inline void version::set_version_id(int32_t value) {
  _internal_set_version_id(value);
  // @@protoc_insertion_point(field_set:notepad_versions.version.version_id)
}

// int32 version_number = 2;
inline void version::clear_version_number() {
  _impl_.version_number_ = 0;
}
inline int32_t version::_internal_version_number() const {
  return _impl_.version_number_;
}
inline int32_t version::version_number() const {
  // @@protoc_insertion_point(field_get:notepad_versions.version.version_number)
  return _internal_version_number();
}
inline void version::_internal_set_version_number(int32_t value) {
  
  _impl_.version_number_ = value;
}
inline void version::set_version_number(int32_t value) {
  _internal_set_version_number(value);
  // @@protoc_insertion_point(field_set:notepad_versions.version.version_number)
}

// string created_time = 3;
inline void version::clear_created_time() {
  _impl_.created_time_.ClearToEmpty();
}
inline const std::string& version::created_time() const {
  // @@protoc_insertion_point(field_get:notepad_versions.version.created_time)
  return _internal_created_time();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void version::set_created_time(ArgT0&& arg0, ArgT... args) {
 
 _impl_.created_time_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:notepad_versions.version.created_time)
}
inline std::string* version::mutable_created_time() {
  std::string* _s = _internal_mutable_created_time();
  // @@protoc_insertion_point(field_mutable:notepad_versions.version.created_time)
  return _s;
}
inline const std::string& version::_internal_created_time() const {
  return _impl_.created_time_.Get();
}
inline void version::_internal_set_created_time(const std::string& value) {
  
  _impl_.created_time_.Set(value, GetArenaForAllocation());
}
inline std::string* version::_internal_mutable_created_time() {
  
  return _impl_.created_time_.Mutable(GetArenaForAllocation());
}
inline std::string* version::release_created_time() {
  // @@protoc_insertion_point(field_release:notepad_versions.version.created_time)
  return _impl_.created_time_.Release();
}
inline void version::set_allocated_created_time(std::string* created_time) {
  if (created_time != nullptr) {
    
  } else {
    
  }
  _impl_.created_time_.SetAllocated(created_time, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.created_time_.IsDefault()) {
    _impl_.created_time_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:notepad_versions.version.created_time)
}

// repeated string file_content = 4;
inline int version::_internal_file_content_size() const {
  return _impl_.file_content_.size();
}
inline int version::file_content_size() const {
  return _internal_file_content_size();
}
inline void version::clear_file_content() {
  _impl_.file_content_.Clear();
}
inline std::string* version::add_file_content() {
  std::string* _s = _internal_add_file_content();
  // @@protoc_insertion_point(field_add_mutable:notepad_versions.version.file_content)
  return _s;
}
inline const std::string& version::_internal_file_content(int index) const {
  return _impl_.file_content_.Get(index);
}
inline const std::string& version::file_content(int index) const {
  // @@protoc_insertion_point(field_get:notepad_versions.version.file_content)
  return _internal_file_content(index);
}
inline std::string* version::mutable_file_content(int index) {
  // @@protoc_insertion_point(field_mutable:notepad_versions.version.file_content)
  return _impl_.file_content_.Mutable(index);
}
inline void version::set_file_content(int index, const std::string& value) {
  _impl_.file_content_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:notepad_versions.version.file_content)
}
inline void version::set_file_content(int index, std::string&& value) {
  _impl_.file_content_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:notepad_versions.version.file_content)
}
inline void version::set_file_content(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.file_content_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:notepad_versions.version.file_content)
}
inline void version::set_file_content(int index, const char* value, size_t size) {
  _impl_.file_content_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:notepad_versions.version.file_content)
}
inline std::string* version::_internal_add_file_content() {
  return _impl_.file_content_.Add();
}
inline void version::add_file_content(const std::string& value) {
  _impl_.file_content_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:notepad_versions.version.file_content)
}
inline void version::add_file_content(std::string&& value) {
  _impl_.file_content_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:notepad_versions.version.file_content)
}
inline void version::add_file_content(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.file_content_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:notepad_versions.version.file_content)
}
inline void version::add_file_content(const char* value, size_t size) {
  _impl_.file_content_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:notepad_versions.version.file_content)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
version::file_content() const {
  // @@protoc_insertion_point(field_list:notepad_versions.version.file_content)
  return _impl_.file_content_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
version::mutable_file_content() {
  // @@protoc_insertion_point(field_mutable_list:notepad_versions.version.file_content)
  return &_impl_.file_content_;
}

// -------------------------------------------------------------------

// version_list

// int32 project_id = 1;
inline void version_list::clear_project_id() {
  _impl_.project_id_ = 0;
}
inline int32_t version_list::_internal_project_id() const {
  return _impl_.project_id_;
}
inline int32_t version_list::project_id() const {
  // @@protoc_insertion_point(field_get:notepad_versions.version_list.project_id)
  return _internal_project_id();
}
inline void version_list::_internal_set_project_id(int32_t value) {
  
  _impl_.project_id_ = value;
}
inline void version_list::set_project_id(int32_t value) {
  _internal_set_project_id(value);
  // @@protoc_insertion_point(field_set:notepad_versions.version_list.project_id)
}

// repeated .notepad_versions.version each_version = 2;
inline int version_list::_internal_each_version_size() const {
  return _impl_.each_version_.size();
}
inline int version_list::each_version_size() const {
  return _internal_each_version_size();
}
inline void version_list::clear_each_version() {
  _impl_.each_version_.Clear();
}
inline ::notepad_versions::version* version_list::mutable_each_version(int index) {
  // @@protoc_insertion_point(field_mutable:notepad_versions.version_list.each_version)
  return _impl_.each_version_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::notepad_versions::version >*
version_list::mutable_each_version() {
  // @@protoc_insertion_point(field_mutable_list:notepad_versions.version_list.each_version)
  return &_impl_.each_version_;
}
inline const ::notepad_versions::version& version_list::_internal_each_version(int index) const {
  return _impl_.each_version_.Get(index);
}
inline const ::notepad_versions::version& version_list::each_version(int index) const {
  // @@protoc_insertion_point(field_get:notepad_versions.version_list.each_version)
  return _internal_each_version(index);
}
inline ::notepad_versions::version* version_list::_internal_add_each_version() {
  return _impl_.each_version_.Add();
}
inline ::notepad_versions::version* version_list::add_each_version() {
  ::notepad_versions::version* _add = _internal_add_each_version();
  // @@protoc_insertion_point(field_add:notepad_versions.version_list.each_version)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::notepad_versions::version >&
version_list::each_version() const {
  // @@protoc_insertion_point(field_list:notepad_versions.version_list.each_version)
  return _impl_.each_version_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace notepad_versions

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_versions_2eproto
